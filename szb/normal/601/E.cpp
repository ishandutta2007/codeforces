#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
vector<ll>g;	const ll bas=10000019,mod=1000000007,N=100010;
struct data{	ll v,w,s,t;	}a[N];
ll n,m,tim,f[40][N],mark[N],cnt,Q;
void work(ll l,ll r,vector<ll>g,ll dep){
	For(i,1,m)	f[dep][i]=f[dep-1][i];
	for(ll i=0;i<g.size();i++)	if (a[g[i]].s<=l&&a[g[i]].t>=r)	FOr(j,m,a[g[i]].w)	f[dep][j]=max(f[dep][j],f[dep][j-a[g[i]].w]+a[g[i]].v);
	if (l==r){
		if (mark[l]){
			ll ans=0;
			FOr(i,m,1)	ans=(ans*bas+f[dep][i])%mod;
			writeln(ans);
		}return;
	}else{
		ll mid=(l+r)>>1;	vector<ll>ls,rs;
		for(ll i=0;i<g.size();i++){
			if (a[g[i]].s<=l&&a[g[i]].t>=r)	continue;
			if (a[g[i]].t<=mid)	ls.push_back(g[i]);
			else	if (a[g[i]].s>mid)	rs.push_back(g[i]);
			else	ls.push_back(g[i]),rs.push_back(g[i]);
		}work(l,mid,ls,dep+1);	work(mid+1,r,rs,dep+1);
	}
}
int main(){
	n=read();	m=read();
	For(i,1,n)	a[++cnt].v=read(),a[cnt].w=read(),a[cnt].s=1;
	Q=read();
	For(i,1,Q){
		ll opt=read();
		if (opt==1)	a[++cnt].v=read(),a[cnt].w=read(),a[cnt].s=i;
		if (opt==2)	a[read()].t=i;
		if (opt==3)	mark[i]=1;
	}
	For(i,1,cnt)	if (!a[i].t)	a[i].t=Q;
	For(i,1,cnt)	g.push_back(i);
	work(1,Q,g,1);
}