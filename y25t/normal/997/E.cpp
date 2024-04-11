#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define fr first
#define sc second
#define ll long long
#define N 120005

int n,m;

int pos[N];

struct seg{
	pii mx;
	int add;
}t[N<<2];
inline void psh(int p,int d){
	t[p].mx.fr+=d,t[p].add+=d;
}
inline void pshd(int p){
	psh(p<<1,t[p].add),psh(p<<1|1,t[p].add);
	t[p].add=0;
}
inline void build(int p,int L,int R){
	if(L==R)
		return t[p].mx={L,L},void();
	int mid=(L+R)>>1;
	build(p<<1,L,mid),build(p<<1|1,mid+1,R);
	t[p].mx=std::max(t[p<<1].mx,t[p<<1|1].mx);
}
inline void add(int p,int L,int R,int l,int r,int d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r)
		return psh(p,d);
	pshd(p);
	int mid=(L+R)>>1;
	add(p<<1,L,mid,l,r,d),add(p<<1|1,mid+1,R,l,r,d);
	t[p].mx=std::max(t[p<<1].mx,t[p<<1|1].mx);
}
inline pii mx(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return {-N,-N};
	if(l<=L&&R<=r)
		return t[p].mx;
	pshd(p);
	int mid=(L+R)>>1;
	return std::max(mx(p<<1,L,mid,l,r),mx(p<<1|1,mid+1,R,l,r));
}

struct node{
	int L,R,tp;
}a[N<<1];
int tot;
std::vector<int> E[N<<1];

int id[N];

#define W 20
int fa[N<<1][W],dep[N<<1],num[N<<1];
ll F[N<<1],f[N<<1][W],g[N<<1][W];
std::vector<ll> S[N<<1];
inline void dfs1(int u){
	for(int i=1;i<W;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<(int)E[u].size();i++){
		int v=E[u][i];
		fa[v][0]=u,dep[v]=dep[u]+1,num[v]=i;
		dfs1(v);
		F[u]+=F[v];
		S[u].push_back((i?S[u].back():0)+F[v]);
	}
	F[u]+=a[u].tp?1ll*E[u].size()*(E[u].size()-1)/2:1;
}
inline void dfs2(int u){
	for(int i=1;i<W;i++){
		f[u][i]=f[u][i-1]+f[fa[u][i-1]][i-1];
		g[u][i]=g[u][i-1]+g[fa[u][i-1]][i-1];
	}
	for(int i=0;i<(int)E[u].size();i++){
		int v=E[u][i];
		f[v][0]=(i?S[u][i-1]:0)+1ll*(a[u].tp>0)*i*(i-1)/2;
		g[v][0]=S[u].back()-S[u][i]+1ll*(a[u].tp>0)*(E[u].size()-i-1)*(E[u].size()-i-2)/2;
		dfs2(v);
	}
}
inline ll sol(int u,int v){
	ll res=0;
	if(dep[u]>dep[v]){
		for(int i=W-1;~i;i--)
			if(dep[fa[u][i]]>dep[v])
				res+=g[u][i],u=fa[u][i];
		res+=g[u][0],u=fa[u][0];
	}
	else if(dep[v]>dep[u]){
		for(int i=W-1;~i;i--)
			if(dep[fa[v][i]]>dep[u])
				res+=f[v][i],v=fa[v][i];
		res+=f[v][0],v=fa[v][0];
	}
	for(int i=W-1;~i;i--)
		if(fa[u][i]!=fa[v][i]){
			res+=g[u][i],u=fa[u][i];
			res+=f[v][i],v=fa[v][i];
		}
	int w=fa[u][0];
	return res+S[w][num[v]-1]-S[w][num[u]]
			+1ll*(a[w].tp>0)*(num[v]-num[u]-1)*(num[v]-num[u]-2)/2;
}

std::stack<int> st;

ll ans;

int main(){
	scanf("%d",&n);
	build(1,1,n+2);
	for(int i=1;i<=n+2;i++){
		int x;
		if(i==1||i==n+2)
			x=i;
		else
			scanf("%d",&x),x++;
		pos[x]=i;
		add(1,1,n+2,1,pos[x-1],1),add(1,1,n+2,1,pos[x+1],1);
		int u=id[i]=++tot;
		a[u].L=a[u].R=i;
		while(st.size()){
			int v=st.top();
			if(a[v].tp&&mx(1,1,n+2,a[v].tp,a[v].tp).fr==i){
				a[v].R=i,a[v].tp=a[u].L;
				E[v].push_back(u);
				st.pop();
				u=v;
				continue;
			}
			if(mx(1,1,n+2,a[v].L,a[v].L).fr==i){
				a[++tot].L=a[v].L,a[tot].R=i,a[tot].tp=a[u].L;
				E[tot].push_back(v),E[tot].push_back(u);
				st.pop();
				u=tot;
				continue;
			}
			auto [p,q]=mx(1,1,n+2,1,a[u].L-1);
			if(p==i){
				a[++tot].L=q,a[tot].R=i;
				E[tot].push_back(u);
				while(st.size()){
					int w=st.top();
					st.pop();
					E[tot].push_back(w);
					if(a[w].L==q)
						break;
				}
				std::reverse(E[tot].begin(),E[tot].end());
				u=tot;
			}
			else
				break;
		}
		st.push(u);
	}
	dfs1(st.top()),dfs2(st.top());
	scanf("%d",&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",sol(id[u],id[v+2]));
	}
}