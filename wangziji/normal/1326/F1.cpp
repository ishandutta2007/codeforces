#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int dp1[3500][70][15];//dp1[i][j][k]nijk 
int dp2[3500][70][15],s1[3500][70][15],s0[3500][70][15];//dp2[i][j][k]n-blijk 
int f1[3500],f2[3500];//f1,f2i 
int e[15][15],P[20],p[10],now1,now2,bl,cnt,ans[20005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char c;
			cin >> c;
			if(c=='1') e[i][j]=1;
		}
	}
	bl=n/2;
	for(int i=n-bl+1;i<=n;i++) P[i]=1;
	do
	{
		++now1;cnt=0;
		for(int i=1;i<=n;i++)
			if(P[i]) f1[now1]|=(1<<i-1),p[++cnt]=i;
		do
		{
			int ans=0;
			for(int i=cnt-1;i>=1;i--) ans<<=1,ans|=e[p[i]][p[i+1]];
			++dp1[now1][ans][p[cnt]];
		}while(next_permutation(p+1,p+cnt+1));
	}while(next_permutation(P+1,P+n+1));
	bl=n-bl;
	memset(P,0,sizeof P);
	for(int i=n-bl+1;i<=n;i++) P[i]=1;
	do
	{
		++now2;cnt=0;
		for(int i=1;i<=n;i++)
			if(P[i]) f2[now2]|=(1<<i-1),p[++cnt]=i;
		do
		{
			int ans=0;
			for(int i=cnt-1;i>=1;i--) ans<<=1,ans|=e[p[i]][p[i+1]];
			++dp2[now2][ans][p[1]];
		}while(next_permutation(p+1,p+cnt+1));
	}while(next_permutation(P+1,P+n+1));
	for(int i=0;i<3500;i++)
	{
		for(int j=0;j<64;j++)
		{
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
					if(e[l][k]) s1[i][j][k]+=dp2[i][j][l];
					else s0[i][j][k]+=dp2[i][j][l];
		}
	}
	bl=n-bl;
	for(int i=1;i<=now1;i++)
	{
		for(int j=1;j<=now2;j++)
		{
//			if(n%2==0&&f1[i]<f2[j]) continue;
			if((f1[i]|f2[j])==(1<<n)-1)
			{
			//	cout << f1[i] << " " << f2[j] << "\n";
				for(int k=0;k<(1<<bl-1);k++)
				{
					for(int l=0;l<(1<<n-bl-1);l++)
					{
						for(int m=1;m<=n;m++)
						{
							ans[(l<<bl)|k|(1<<bl-1)]+=dp1[i][k][m]*s1[j][l][m];
							ans[(l<<bl)|k]+=dp1[i][k][m]*s0[j][l][m];
						//	for(int N=1;N<=n;N++)
						//	{
						//		if(	e[N][m])
						//		ans[(l<<bl)|k|(e[N][m]<<bl-1)]+=dp1[i][k][m]*dp2[j][l][N];
					//			if(((k<<n-bl)|l|(e[n][m]<<n-bl-1))==1&&dp1[i][k][m]*dp2[j][l][N]) cout << i << " " << j << " " << k << " " << l << " " << m << " " << N << "\n";
							//	if(l==0) cout << dp2[j][l][N] << " " << j << " " << l << " " << N << "\n";
						//	}
					//		ans[(k<<n-bl)|l|(1<<n-bl-1)]+=s1[i][k][m],ans[(k<<n-bl)|l]+=s0[i][k][m];
						} 
					}
				}
			}
		}
	}
//	if(n%2==0)
//		for(int i=0;i<(1<<n+1);i++) ans[i]<<=1; 
	for(int i=0;i<(1<<n-1);i++) cout << ans[i] << " ";
	return 0;
}