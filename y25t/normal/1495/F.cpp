#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#include<set>
#define ll long long
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 200005

int n,m,p[N],a[N],b[N];

bool vis[N];

pii A[N<<1];
int r[N];
std::stack<int> st;

std::vector<int> rt;

ll sa[N],f[N],g[N];

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

inline void dfs(int u){
	ll tmp=0;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		dfs(v);
		tmp+=f[v];
	}
	f[u]=std::min(f[u],tmp);
	g[u]=f[u]-tmp;
}

std::set<int> s;

struct node{
	int l,r;
	ll val;
	int id;
}q[N<<2];
int tot;
inline bool cmp(node x,node y){
	return x.r!=y.r?x.r<y.r:x.id<y.id;
}

ll t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,ll d){
	for(;x<=n+1;x+=lb(x))
		t[x]+=d;
}
inline ll sum(int x){
	ll res=0;
	for(;x;x-=lb(x))
		res+=t[x];
	return res;
}

ll ans[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sa[i]=sa[i-1]+a[i];
	}
	sa[n+1]=sa[n];
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		while(st.size()&&p[st.top()]<p[i]){
			r[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	while(st.size()){
		r[st.top()]=n+1;
		st.pop();
	}
	for(int i=1;i<=n;i++){
		A[i]=mp(i,i);
		A[i+n]=mp(r[i],-i);
		f[i]=std::min(0ll,b[i]-(sa[r[i]-1]-sa[i-1]));
	}
	std::sort(A+1,A+n+n+1);
	for(int i=1;i<=n+n;i++){
		if(A[i].sec<0){
			st.pop();
			if(st.size())
				addedge(st.top(),-A[i].sec);
			else
				rt.push_back(-A[i].sec);
		}
		else
			st.push(A[i].sec);
	}
	for(auto u:rt)
		dfs(u);
	s.insert(1);
	s.insert(n+1);
	q[++tot]=(node){1,n+1,1,0};
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		if(x==1)
			continue;
		if(!vis[x]){
			vis[x]=1;
			auto it=s.insert(x).fir,L=it,R=it;
			R++;
			if(L!=s.begin()){
				L--;
				q[++tot]=(node){*L,x,1,i};
				q[++tot]=(node){*L,*R,-1,i};
			}
			q[++tot]=(node){x,*R,1,i};
		}
		else{
			vis[x]=0;
			auto it=s.find(x),L=it,R=it;
			R++;
			if(L!=s.begin()){
				L--;
				q[++tot]=(node){*L,x,-1,i};
				q[++tot]=(node){*L,*R,1,i};
			}
			q[++tot]=(node){x,*R,-1,i};
			s.erase(it);
		}
	}
	for(int i=1;i<=n;i++)
		q[++tot]=(node){i,r[i],g[i],-i};
	std::sort(q+1,q+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(q[i].id>=0)
			ans[q[i].id]+=1ll*q[i].val*(sum(q[i].l)+sa[q[i].r-1]-sa[q[i].l-1]);
		else{
			add(1,q[i].val);
			add(q[i].l+1,-q[i].val);
		}
	}
	for(int i=1;i<=m;i++)
		ans[i]+=ans[i-1];
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	puts("");
}