#include<cstring>
#include<string>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll int
#define maxn 10000010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
int pri[maxn],bin[maxn],a[maxn],mu[maxn],ans,an,n,k,sz[maxn],mx;
bool mark[maxn];
const ll mod=1e9+7;
void init(ll N){
	mu[1]=1;
	For(i,2,N){
		if (!mark[i])	pri[++pri[0]]=i,mu[i]=-1;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			mark[i*pri[j]]=1;
			if (!(i%pri[j])){
				mu[i*pri[j]]=0;
				break;
			}mu[i*pri[j]]=-mu[i];
		}
	}
}
int main(){
	n=read();
	bin[0]=1;	For(i,1,n)	bin[i]=bin[i-1]*2%mod;
	For(i,1,n)	a[i]=read(),mx=max(mx,a[i]),sz[a[i]]++;
	init(mx);
	For(i,2,mx)if (mu[i]){
		ll an=0;
		for(ll j=i;j<=mx;j+=i)	an+=sz[j];
		if (!an)	continue;
		an=1LL*(bin[an]-1)*(n-an)%mod;
		mu[i]==-1?ans=(ans+an)%mod:ans=(ans-an)%mod;
	}
	writeln((ans+mod)%mod);
}
/*
g[x]
f[x]-=f[d] 
3
2 3 2
*/