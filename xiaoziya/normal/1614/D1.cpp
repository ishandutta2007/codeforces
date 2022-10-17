#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=20000005;
int n,ps,mx;
int c[maxn],p[maxn],g[maxn];
long long f[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),g[x]++,f[x]+=x,mx=max(mx,x);
	c[1]=1;
	for(int i=2;i<=mx;i++){
		if(c[i]==0)
			p[++ps]=i;
		for(int j=1;j<=ps&&i*p[j]<=mx;j++){
			c[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	for(int i=1;i<=ps;i++)
		for(int j=mx/p[i];j>=1;j--)
			g[j]+=g[j*p[i]];
	for(int i=mx;i>=1;i--)
		for(int j=1;j<=ps&&i*p[j]<=mx;j++)
			f[i]=max(f[i],f[i*p[j]]+1ll*(g[i]-g[i*p[j]])*i);
	printf("%lld\n",f[1]);
	return 0;
}