#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)	for(int i=x;i>=y;--i)
#define maxn 300010
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
bool cmp(ll a,ll b){	return a>b;	}
inline void write(ll x){    if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
const ll mod=1e9+7;
ll bin[maxn],a[maxn],n,ans;
int main(){
	bin[0]=1;	For(i,1,300000)	bin[i]=bin[i-1]*2%mod;
	n=read();
	For(i,1,n)	a[i]=read();
	sort(a+1,a+n+1);
	For(i,1,n){
		ans=(ans-(bin[n-i]-1)*a[i])%mod;
		ans=(ans+(bin[i-1]-1)*a[i])%mod;
	}
	writeln((ans+mod)%mod);
}