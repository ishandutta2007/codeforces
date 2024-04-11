#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int maxn=4007;
int dp[maxn][maxn][2],w,d,k,rw,rd,fac[maxn],C[maxn][maxn];
bool col[maxn],row[maxn];


void prec(){
	fac[0]=1;
	for (int i=1;i<maxn;++i){
		fac[i]=(1LL*fac[i-1]*i)%mod;
	}
	for (int i=0;i<maxn;++i){
		C[i][0]=C[i][i]=1;
	}
	for (int i=1;i<maxn;++i){
		for (int j=1;j<i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
} 
int main(){
	prec();
	scanf("%d%d%d",&w,&d,&k);
	for (int i=1;i<=k;++i){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		col[y1]=col[y2]=1,row[x1]=row[x2]=1;
	}
	for (int i=1;i<=w;++i){
		if (!row[i]) rw++;
	}
	for (int i=1;i<=d;++i){
		if (!col[i]) rd++;
	}
	dp[0][0][0]=dp[0][0][1]=1;
	for (int i=1;i<=w;++i){
		dp[i][0][0]=1;
		for (int j=1;j<=rw/2;++j){
			if (i>1&&!row[i]&&!row[i-1]) dp[i][j][0]=(dp[i][j][0]+dp[i-2][j-1][0])%mod;
			dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0])%mod;
		}
	}
	for (int i=1;i<=d;++i){
		dp[i][0][1]=1;
		for (int j=1;j<=rd/2;++j){
			if (i>1&&!col[i]&&!col[i-1]) dp[i][j][1]=(dp[i][j][1]+dp[i-2][j-1][1])%mod;
			dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][1])%mod;
		}
	}
	long long ans=0;
	for (int i=0;i<=rw/2;++i){
		for (int j=0;j<=rd/2;++j){
			int u=(1LL*dp[w][i][0]*C[rw-2*i][j])%mod,v=(1LL*dp[d][j][1]*C[rd-2*j][i])%mod,w=(1LL*u*v)%mod,x=(1LL*fac[i]*fac[j])%mod;
			ans=(ans+1LL*w*x)%mod;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}