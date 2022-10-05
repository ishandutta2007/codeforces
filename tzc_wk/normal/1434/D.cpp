#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
struct edge{
	int u,v,t;
} e[500005];
int n,dep0[500005];
vector<pii> g[500005];
inline void getrt(int x,int f){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i].fi;if(y==f) continue;
		dep0[y]=dep0[x]+1;getrt(y,x);
	}
}
struct tree{
	struct node{
		int l,r,mx[2],lz;
	} s[500005<<2];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	inline void update(int k,int x,int v,int y){
		if(s[k].l==s[k].r){
			s[k].mx[v&1]=y;
			return;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(x<=mid) update(k<<1,x,v,y);
		else update(k<<1|1,x,v,y);
		s[k].mx[0]=max(s[k<<1].mx[0],s[k<<1|1].mx[0]);
		s[k].mx[1]=max(s[k<<1].mx[1],s[k<<1|1].mx[1]);
	}
	inline void pushdown(int k){
		if(s[k].lz){
			swap(s[k<<1].mx[0],s[k<<1].mx[1]);
			swap(s[k<<1|1].mx[0],s[k<<1|1].mx[1]);
		}
		s[k<<1].lz^=s[k].lz;s[k<<1|1].lz^=s[k].lz;
		s[k].lz=0;
	}
	inline void add(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			swap(s[k].mx[0],s[k].mx[1]);
			s[k].lz^=1;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid) add(k<<1,l,r);
		else if(l>mid) add(k<<1|1,l,r);
		else add(k<<1,l,mid),add(k<<1|1,mid+1,r);
		s[k].mx[0]=max(s[k<<1].mx[0],s[k<<1|1].mx[0]);
		s[k].mx[1]=max(s[k<<1].mx[1],s[k<<1|1].mx[1]);
	}
};
struct qaqwq{
private:
	tree st;
	int L[500005],R[500005],rid[500005],tim=0,cnt[500005],dep[500005];
public:
	inline void dfs(int x,int f){
		L[x]=++tim;rid[tim]=x;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].fi,z=g[x][i].se;
			if(y==f) continue;dep[y]=dep[x]+1;
			cnt[y]=cnt[x]+z;dfs(y,x);
		}
		R[x]=tim;
	}
	inline void init(int rt){
		st.build(1,1,n);dfs(rt,0);
		for(int i=1;i<=n;i++) st.update(1,L[i],cnt[i],dep[i]);
	}
	inline void perform(int u,int v){
		if(dep[u]>dep[v]) swap(u,v);
		st.add(1,L[v],R[v]);
	}
	inline int query(){return st.s[1].mx[0];}
} p1,p2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,t;scanf("%d%d%d",&u,&v,&t);e[i]={u,v,t};
		g[u].pb(make_pair(v,t));g[v].pb(make_pair(u,t));
	} getrt(1,0);
	int s1=1,s2=1,mx=0;
	for(int i=1;i<=n;i++) if(dep0[i]>mx) mx=dep0[i],s1=i;
	dep0[s1]=0;getrt(s1,0);mx=0;
	for(int i=1;i<=n;i++) if(dep0[i]>mx) mx=dep0[i],s2=i;
	p1.init(s1);p2.init(s2);
	int m;scanf("%d",&m);
	while(m--){
		int x;scanf("%d",&x);
		p1.perform(e[x].u,e[x].v);p2.perform(e[x].u,e[x].v);
		printf("%d\n",max(p1.query(),p2.query()));
	}
	return 0;
}