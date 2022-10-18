#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define fr first
#define sc second
#define ll long long
#define N 300005

int n,A[N];

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

std::stack<int> st;

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		A[x]=y;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int x=A[i];
		pos[x]=i;
		add(1,1,n,1,pos[x-1],1),add(1,1,n,1,pos[x+1],1);
		int u=++tot;
		a[u].L=a[u].R=i;
		while(st.size()){
			int v=st.top();
			if(a[v].tp&&mx(1,1,n,a[v].tp,a[v].tp).fr==i){
				a[v].R=i,a[v].tp=a[u].L;
				E[v].push_back(u);
				st.pop();
				u=v;
				continue;
			}
			if(mx(1,1,n,a[v].L,a[v].L).fr==i){
				a[++tot].L=a[v].L,a[tot].R=i,a[tot].tp=a[u].L;
				E[tot].push_back(v),E[tot].push_back(u);
				st.pop();
				u=tot;
				continue;
			}
			auto [p,q]=mx(1,1,n,1,a[u].L-1);
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
	for(int i=1;i<=tot;i++)
		ans+=a[i].tp?1ll*E[i].size()*(E[i].size()-1)/2:1;
	printf("%lld\n",ans);
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikj
	//kjhgfdswertyuikjnbvcxsertyuikjv
}