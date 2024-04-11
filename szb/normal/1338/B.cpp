#include<bits/stdc++.h>
//#include<unistd.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll N=100010;
vector<ll>g[N];
ll ans1,ans2,n,a[N],ye[N],dep[N],lnk[N],vis[N],q[N],ind[N];
ll h,t;
void dfs(ll x){
	vis[x]=1;dep[x]=0;
	rep(i,0,g[x].size()){
		ll to=g[x][i];
		if (vis[to])continue;
		dfs(to);
		if (!dep[x])dep[x]=dep[to]^1;
		else if (dep[x]!=(dep[to]^1))ans1=3;
	}if (!dep[x])dep[x]=2;
}
int main(){
	n=read();
	For(i,2,n){
		ll a=read(),b=read();
		g[a].pb(b);g[b].pb(a);
		++ind[a];++ind[b];
	}
	For(i,1,n)if (ind[i]==1)++ye[g[i][0]],q[++t]=i,dep[i]=0;
	ans1=1;
	dfs(1);
	if (ind[1]==1){
		if (dep[1]==3)ans1=3;
	}
	ans2=n-1;	For(i,1,n)ans2-=max(ye[i]-1,0ll);
	cout<<ans1<<' '<<ans2<<endl;
}