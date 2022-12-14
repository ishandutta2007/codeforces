#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
#define ll long long
#define mod 1000000007
int f[N][N],A,B,invA,invB,invs,n,ans;
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int main()
{
	// freopen("string.in","r",stdin);
	// freopen("string.out","w",stdout);
	scanf("%d%d%d",&n,&A,&B);invA=q_pow(A,mod-2),invB=q_pow(B,mod-2);invs=q_pow(A+B,mod-2);
	f[0][1]=1;
	for(int i=0;i<n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i+j<n)f[i+j][j]=(f[i+j][j]+(ll)f[i][j]*B%mod*invs)%mod;
			f[i][j+1]=(f[i][j+1]+(ll)f[i][j]*A%mod*invs)%mod;
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)if(i+j>=n)ans=(ans+(ll)f[i][j]*B%mod*invs%mod*(i+j))%mod;
		ans=(ans+(ll)f[i][n]*((ll)A*invB%mod+i+n))%mod;
	}
	printf("%d\n",ans);
}