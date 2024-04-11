#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=150005;
struct edge{
	int to,next;
}e[N*2];
struct node{
	int l;
	ll F,sum;
};
vector<node> vec[N];
int head[N],tot,n,q[N];
int a[N],vis[N],sz[N],mxv,rt;
int ls[N],rs[N],nd;
ll ans;
pll t[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
ll FFF(pll x,int y){
	return y*x.fi+x.se;
}
void insert(int &k,int l,int r,pll x){
	if (!k){
		k=++nd;
		t[k]=x;
		return;
	}
	int mid=(l+r)/2;
	if (FFF(x,mid)>FFF(t[k],mid)) swap(t[k],x);
	if (FFF(x,l)>FFF(t[k],l)) insert(ls[k],l,mid,x);
	if (FFF(x,r)>FFF(t[k],r)) insert(rs[k],mid+1,r,x);
}
ll ask(int k,int l,int r,int p){
	if (!k) return -(1ll<<60);
	ll ans=FFF(t[k],p);
	int mid=(l+r)/2;
	if (p<=mid) return max(ans,ask(ls[k],l,mid,p));
	return max(ans,ask(rs[k],mid+1,r,p));
}
void get_sta(int x,int fa,int be,int l,ll F,ll sum){
	++l;
	sum+=a[x];
	F+=1ll*l*a[x];
	vec[be].PB((node){l,F,sum});
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			get_sta(e[i].to,x,be,l,F,sum);
}
void upd_ans(int x){
	For(i,1,*q){
		for (auto j:vec[q[i]])
			ans=max(ans,1ll*(j.l+1)*(j.sum-a[x])-(j.F-a[x])+ask(rt,0,n,j.l-1));
		for (auto j:vec[q[i]]) insert(rt,0,n,pll(j.sum,j.F));
	}
	for (;nd;nd--){
		ls[nd]=rs[nd]=0;
		t[nd]=pll(0,0);
	}
	rt=0;
	Rep(i,*q,1){
		for (auto j:vec[q[i]])
			ans=max(ans,1ll*(j.l+1)*(j.sum-a[x])-(j.F-a[x])+ask(rt,0,n,j.l-1));
		for (auto j:vec[q[i]]) insert(rt,0,n,pll(j.sum,j.F));
	}
	for (;nd;nd--){
		ls[nd]=rs[nd]=0;
		t[nd]=pll(0,0);
	}
	rt=0;
}
void dfs(int x,int fa,int n){
	sz[x]=1; int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			dfs(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	mx=max(mx,n-sz[x]);
	if (mx<mxv) mxv=mx,rt=x;
}
void solve(int x,int n){
	mxv=1<<30; dfs(x,0,n);
	vis[x=rt]=1; q[0]=1; q[1]=x;
	vec[x].resize(0); rt=0;
	vec[x].PB((node){1,a[x],a[x]});
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			q[++*q]=e[i].to;
			vec[e[i].to].resize(0);
			get_sta(e[i].to,x,e[i].to,1,a[x],a[x]);
		}
	upd_ans(x);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to])
			solve(e[i].to,sz[e[i].to]>sz[x]?n-sz[x]:sz[e[i].to]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	For(i,1,n) scanf("%d",&a[i]);
	solve(1,n);
	printf("%lld\n",ans);
}