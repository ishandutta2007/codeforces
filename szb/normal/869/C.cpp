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
const ll mod=998244353;
inline void writeln(ll x){ wrote(x);   puts("");   }
ll f[5100][5010],A,B,C;
int main(){
	A=read();	B=read();	C=read();
	For(i,0,5000)	f[0][i]=1;
	For(i,1,5000){
		f[i][0]=1;
		For(j,1,5000)	f[i][j]=(f[i-1][j-1]*j+f[i-1][j])%mod;
	}
	writeln(f[A][B]*f[A][C]%mod*f[B][C]%mod);
}