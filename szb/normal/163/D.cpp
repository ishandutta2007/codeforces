#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 2000000001
#define maxn 110
#define mod 100000000
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
ll t,n,ans,a[maxn],b[maxn],V,ch_x,ch_y,ch_z,ss;
void dfs(ll A,ll x,ll dep){
	if (A>ss)	return;
	if (dep>n){
		ll y=V/x/A,now=(x*y+x*A+y*A);
//		printf("%lld %lld %lld %lld\n",A,x,y,now);
		if (now<ans)	ans=now,ch_x=x,ch_y=y,ch_z=A;
		return;
	}
	if (b[dep])	b[dep]--,dfs(A,x*a[dep],dep),b[dep]++;
	dfs(A,x,dep+1);
}
void dfs(ll x,ll dep){
	if (x>t)	return;
	if (dep>n){
		if (2*x*sqrt(V/x)+V/x>=ans)	return;
		ss=sqrt(V/x)+1e-8;	dfs(x,1,1);	return;
	}
	if (b[dep])	b[dep]--,dfs(x*a[dep],dep),b[dep]++;
	dfs(x,dep+1);
}
int main(){
	ll T=read();
	while(T--){
		n=read();	V=1;
		For(i,1,n){
			a[i]=read(),b[i]=read();
			For(j,1,b[i])	V*=a[i];
		}
		t=pow(V,1.0/3)+1e-8;	ans=5e18;	dfs(1,1);
		printf("%lld %lld %lld %lld\n",ans*2,ch_x,ch_y,ch_z);
	}
}