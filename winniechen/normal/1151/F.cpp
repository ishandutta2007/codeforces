#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define N 105
const int mod = 1000000007;
int a[N],n,K,sn;
struct Mat
{
	int a[N][N];
	Mat(){memset(a,0,sizeof(a));}
	Mat operator * (const Mat &b) const 
	{
		Mat c = Mat();
		for(int i=0;i<=sn;i++)for(int j=0;j<=sn;j++)for(int k=0;k<=sn;k++)
			c.a[i][j]=(c.a[i][j]+(ll)a[i][k]*b.a[k][j])%mod;
		return c;
	}
}ret,map;
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
void q_pow(int K){for(;K;K>>=1,map=map*map)if(K&1)ret=ret*map;}
int main()
{
	scanf("%d%d",&n,&K);int now=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sn+=a[i]==1;
	for(int i=n-sn+1;i<=n;i++)now+=a[i]==1;ret.a[0][now]=1;
	for(int i=0;i<=sn;i++)
	{
		map.a[i][i-1]=i*(n-sn*2+i);
		map.a[i][i+1]=(sn-i)*(sn-i);
		map.a[i][i]=(n*(n-1)>>1)-i*(n-sn*2+i)-(sn-i)*(sn-i);
	}q_pow(K);
	printf("%lld\n",((ll)ret.a[0][sn]*q_pow(q_pow(n*(n-1)>>1,mod-2),K)%mod+mod)%mod);
}