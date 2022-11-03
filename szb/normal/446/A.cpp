#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<memory.h> 
#define ll long long
#define inf 20000000000
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(ll x){
	if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}
void writeln(ll x){
	write(x);
	printf("\n");
}
ll n,f[1000001],g[1000001],a[1000001],ans=1;
int main(){
	n=read();
	for (ll i=1;i<=n;i++)	a[i]=read();
	for (ll i=1;i<=n;i++)	f[i]=f[i-1]*(a[i-1]<a[i])+1;
	g[n]=1;
	a[0]=-inf;	a[n+1]=inf;
	for (ll i=n-1;i;i--)	g[i]=g[i+1]*(a[i]<a[i+1])+1;
	for (ll i=1;i<=n;i++){
		if (a[i+1]-a[i-1]>1)	ans=max(ans,f[i-1]+g[i+1]+1);
		ans=max(f[i],ans);
		ans=max(g[i],ans);
		ans=max(f[i-1]+1,ans);
		ans=max(g[i+1]+1,ans);
	}
	writeln(ans);
}