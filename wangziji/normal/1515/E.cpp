#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
unsigned long long dp[405][405],C[405][405],qwq[405][405],DP[405][405];
signed main(int argc, char** argv) {
	int n,mod;
	cin >> n >> mod;
	//n=400,mod=234567899;
	for(int i=0;i<=400;i++)
	{
		C[0][i]=C[i][i]=1;
		if(i) for(int j=1;j<i;j++)
			C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
	}
	qwq[1][0]=1;
	dp[1][1]=1;
	DP[1][1]=1;
	DP[0][0]=1;
	dp[0][0]=1;
	qwq[0][0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int x=j,y=i-j-1;
			if(x>=y) break;
			for(int k=x/2;k<=x;k++)
			{
				int l=y/2;
				for(;l+3<=y;l+=4)
				{
					int QWQ=qwq[x][k];
					qwq[i][k+l+1]=(qwq[i][k+l+1]+QWQ*qwq[y][l]%mod*C[k][k+l]);
					qwq[i][k+l+2]=(qwq[i][k+l+2]+QWQ*qwq[y][l+1]%mod*C[k][k+l+1]);
					qwq[i][k+l+3]=(qwq[i][k+l+3]+QWQ*qwq[y][l+2]%mod*C[k][k+l+2]);
					qwq[i][k+l+4]=(qwq[i][k+l+4]+QWQ*qwq[y][l+3]%mod*C[k][k+l+3]);
		//			cout << l << " " << l+1 << " " << l+2 << " " << l+3 << " " ;
				}
		//		cout << l << "**";
//				++l;
				for(;l<=y;l++)
				{
					
				//	cout <<l << " ";
					qwq[i][k+l+1]=(qwq[i][k+l+1]+qwq[x][k]*qwq[y][l]%mod*C[k][k+l]);
				}
			/*	for(int l=y/2;l<=y;l++)
				{
					qwq[i][k+l+1]=(qwq[i][k+l+1]+qwq[x][k]*qwq[y][l]%mod*C[k+l][k])%mod;
				}*/
				if(k%8==0)
				{
					for(int j=1;j<=i;j++) qwq[i][j]%=mod;
				}
			}
		}
					for(int j=1;j<=i;j++) qwq[i][j]%=mod;
		for(int j=0;j<i;j++)
		{
			int x=j,y=i-j-1;
		//	cout << y << "\n";
			if(x>=y) break;
			for(int k=x/2;k<=x;k++)
			{
				int l=y/2;
				for(;l+3<=y;l+=4)
				{
					int QWQ=qwq[x][k];
					dp[i][k+l+1]=(dp[i][k+l+1]+(QWQ*dp[y][l]+dp[x][k]*qwq[y][l])%mod*C[k][k+l]);
					dp[i][k+l+2]=(dp[i][k+l+2]+(QWQ*dp[y][l+1]+dp[x][k]*qwq[y][l+1])%mod*C[k][k+l+1]);
					dp[i][k+l+3]=(dp[i][k+l+3]+(QWQ*dp[y][l+2]+dp[x][k]*qwq[y][l+2])%mod*C[k][k+l+2]);
					dp[i][k+l+4]=(dp[i][k+l+4]+(QWQ*dp[y][l+3]+dp[x][k]*qwq[y][l+3])%mod*C[k][k+l+3]);
		//			cout << l << " " << l+1 << " " << l+2 << " " << l+3 << " " ;
				}
		//		cout << l << "**";
//				++l;
				for(;l<=y;l++)
				{
					
				//	cout <<l << " ";
					dp[i][k+l+1]=(dp[i][k+l+1]+(qwq[x][k]*dp[y][l]+dp[x][k]*qwq[y][l])%mod*C[k][k+l]);
				}
				if(k%4==0)
				{
					for(int j=1;j<=i;j++) dp[i][j]%=mod;
				}
	//			cout << y << " " << "\n";
			}
		}
					for(int j=1;j<=i;j++) dp[i][j]%=mod;
		for(int j=0;j<=i;j++)
			qwq[i][j]=(qwq[i][j]+qwq[i][j])%mod;
		for(int j=0;j<i;j++)
		{
			int x=j,y=i-j-1;
			if(x!=y) continue;
			for(int k=x/2;k<=x;k++)
			{
				for(int l=y/2;l<=y;l++)
				{
					dp[i][k+l+1]=(dp[i][k+l+1]+qwq[x][k]*dp[y][l]%mod*C[k][k+l])%mod;
					qwq[i][k+l+1]=(qwq[i][k+l+1]+qwq[x][k]*qwq[y][l]%mod*C[k][k+l])%mod;
				}
			}
		}
	}
	for(int i=n;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int x=j,y=i-j-1;
			for(int k=x/2;k<=x;k++)
			{
				for(int l=y/2;l<=y;l++)
				{
					DP[i][k+l+1]=(DP[i][k+l+1]+(long long)dp[x][k]*dp[y][l]%mod*C[k][k+l])%mod;
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=DP[n][i];
	cout << ans%mod;
	return 0;
}