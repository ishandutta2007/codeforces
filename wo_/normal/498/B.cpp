#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

double dp[2][5002];

int main(){
	int N,T;
	scanf("%d%d",&N,&T);
	int t=0;
	dp[0][0]=1;
	double ans=0;
	for(int i=0;i<N;i++){
		int p_,k;
		scanf("%d%d",&p_,&k);
		double p=p_/100.0;
		for(int j=0;j<5002;j++) dp[1-t][j]=0;
		for(int j=0;j<5001;j++){
			double nxt=dp[1-t][j];
			if(j-k>=0) nxt-=dp[t][j-k]*pow(1-p,k-1);
			nxt*=(1-p);
			nxt+=dp[t][j]*p;
			if(j-k+1>=0) nxt+=dp[t][j-k+1]*pow(1-p,k);
			dp[1-t][j+1]=nxt;
		}
	//	for(int j=0;j<=T+1;j++) printf("%f ",dp[1-t][j]);
	//	printf("\n");
		for(int j=0;j<=T;j++) ans+=dp[1-t][j];
		t^=1;
	}
	printf("%.9f\n",ans);
	return 0;
}