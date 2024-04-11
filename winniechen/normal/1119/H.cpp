#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 100005
#define M 1<<17
#define mod 998244353
#define ll long long
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
ll ans[M];
int A[M],B[M],C[M],n,K,x,y,z;
void FWT(int *a,int len)
{
	for(int k=2,t=1;k<=len;k<<=1,t<<=1)
		for(int i=0;i<len;i+=k)
			for(int j=i,tmp;j<i+t;j++)
				tmp=a[j]-a[j+t],a[j]+=a[j+t],a[j+t]=tmp;
}
void IFWT(ll *a,int len)
{
	ll tmp;
	for(int k=2,t=1;k<=len;k<<=1,t<<=1)
		for(int i=0;i<len;i+=k)
			for(int j=i;j<i+t;j++)
				tmp=a[j]-a[j+t],a[j]+=a[j+t],a[j+t]=tmp;
	tmp=q_pow(len,mod-2);for(int i=0;i<len;i++)a[i]=a[i]%mod*tmp%mod;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&K,&x,&y,&z);int now=0;
	for(int i=1,a,b,c;i<=n;i++)
		scanf("%d%d%d",&a,&b,&c),now^=a,A[b^a]++,B[c^a]++,C[b^c]++;
	FWT(A,1<<K),FWT(B,1<<K),FWT(C,1<<K);
	int v1=((ll)x+y+z)%mod,v2=(x-y+z)%mod,v3=(x+y-z)%mod,v4=(x-y-z)%mod;
	for(int i=0;i<1<<K;i++)
		ans[i]=(ll)q_pow(v1,(n+A[i]+B[i]+C[i])>>2)*q_pow(v2,(n+B[i]-C[i]-A[i])>>2)%mod
				*q_pow(v3,(n+A[i]-B[i]-C[i])>>2)%mod*q_pow(v4,(n+C[i]-A[i]-B[i])>>2)%mod;
	IFWT(ans,1<<K);
	for(int i=0;i<1<<K;i++)printf("%lld ",(ans[i^now]+mod)%mod);puts("");
}