#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=300010;
ll n,k,a[N],pre[N],f[5010][5010];
int main(){
	n=read();	k=read();
	For(i,1,n)	a[i]=read();
	sort(a+1,a+n+1);
	ll sum_more=n%k,sum_less=k-sum_more;
	memset(f,60,sizeof f);
	f[0][0]=0;
	For(i,0,sum_more)	For(j,0,sum_less){
		ll now=i*(n/k+1)+j*(n/k);
		if (i)	f[i][j]=min(f[i][j],f[i-1][j]+a[now]-a[now-n/k]);
		if (j)	f[i][j]=min(f[i][j],f[i][j-1]+a[now]-a[now-n/k+1]);
	}writeln(f[sum_more][sum_less]);
}