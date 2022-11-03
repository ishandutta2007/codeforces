#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll maxn=111;
double p[maxn],win,tim;
ll n,a[maxn];
int main(){
//	freopen("a.in","r",stdin);
	n=read();	win=1;
	For(i,1,n){
		p[i]=(a[i]=read())*0.01;
		win*=p[i];
	}tim=n;
	for(ll it=0;((1-win)>1e-10)&&(it<=500000);it++){
		tim+=1-win;
		ll cho=0;	double cho_v=0;
		For(i,1,n){
			double now_v=(1-p[i])*a[i]*0.01/p[i];
			if (now_v>cho_v)	cho_v=now_v,cho=i;
		}
		win=1;
		p[cho]+=(1-p[cho])*a[cho]*0.01;
		For(i,1,n)	win=win*p[i];
	}printf("%lf\n",tim);
}