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
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
struct node{
	int v1,v2,vp,id;
};
vector<node> vec1,vec2;
map<int,int> mp1,mp2;
int n,mod,bas,wzp;
int a[N],in[N],out[N];
int head[N],sz[N],vis[N];
int rt,tot;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mod)
		if (y&1) s=1ll*s*x%mod;
	return s;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa,int n){
	sz[x]=1; int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			dfs(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	if (mx*2<n&&sz[x]*2>=n) rt=x;
}
void color(int x,int fa,int v1,int v2,int vp,int d){
	vp=1ll*vp*bas%mod; d++;
	v1=(1ll*v1*bas+a[x])%mod;
	v2=(v2+1ll*a[x]*vp)%mod;
	vec1.PB((node){v1,v2,vp,x});
	vec2.PB((node){v1,v2,vp,x});
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			color(e[i].to,x,v1,v2,vp,d);
}
void upd_ans(vector<node> vec,int dif){
	mp1.clear(); mp2.clear();
	for (auto i:vec) ++mp1[i.v2];
	for (auto i:vec){
		int val=1ll*(wzp+mod-i.v1)*power(i.vp,mod-2)%mod;
		in[i.id]+=mp1[val]*dif; mp2[val]+=dif; 
	}
	for (auto i:vec) out[i.id]+=mp2[i.v2];
}
void solve(int x,int n){
	dfs(x,0,n); vis[x=rt]=1;
	vec1.resize(0);
	vec1.PB((node){a[x],0,1,x});
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			vec2.resize(0);
			color(e[i].to,x,a[x],0,1,1);
			upd_ans(vec2,-1);
		} 
	upd_ans(vec1,1);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to])
			solve(e[i].to,sz[e[i].to]<sz[x]?sz[e[i].to]:n-sz[x]);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d%d",&n,&mod,&bas,&wzp);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	solve(1,n);
	ll ans=0;
	For(i,1,n) ans+=1ll*(in[i]+out[i])*(2*n-in[i]-out[i]);
	For(i,1,n) ans+=1ll*in[i]*(n-in[i]);
	For(i,1,n) ans+=1ll*out[i]*(n-out[i]);
	//For(i,1,n) cout<<in[i]<<' '<<out[i]<<' '<<ans<<endl;
	ans=1ll*n*n*n-ans/2;
	printf("%lld\n",ans);
}
/*
3-3:1
3-2:0
3-1:4
2-3:2
2-2:3
2-1:0
1-3:3
1-2:1
1-1:4 
*/