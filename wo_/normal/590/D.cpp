#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=1e9;

int a[200];
int N,K;
int S;

int dp[2][200][200*200];

int main(){
	scanf("%d%d",&N,&K);
	scanf("%d",&S);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	S=min(S,N*(N-1)/2);
	for(int i=0;i<=N;i++) for(int j=0;j<=S;j++) dp[0][i][j]=inf;
	dp[0][0][0]=0;
	int t=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++) for(int k=0;k<=S;k++){
			dp[t^1][j][k]=inf;
		}
		for(int j=0;j<=N;j++) for(int k=0;k<=S;k++){
			if(dp[t][j][k]==inf) continue;
			int x=i-j;
			if(j+1<=K&&k+x<=S){
				dp[t^1][j+1][k+x]=min(dp[t^1][j+1][k+x],dp[t][j][k]+a[i]);
			}
			dp[t^1][j][k]=min(dp[t^1][j][k],dp[t][j][k]);
		}
		t^=1;
	}
	int ans=inf;
	for(int i=0;i<=S;i++){
		ans=min(ans,dp[t][K][i]);
	}
	printf("%d\n",ans);
	return 0;
}