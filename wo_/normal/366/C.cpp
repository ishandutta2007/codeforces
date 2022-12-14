#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=1<<28;
const int NUM=100000;

int a[110],b[110];
int d[110];

int dp[200200][110];

int N;

int main(){
	int K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++) scanf("%d",b+i);
	for(int i=0;i<N;i++) d[i]=a[i]-K*b[i];
/*	for(int i=0;i<N;i++){
		scanf("%d%d",a+i,b+i);
		d[i]=a[i]-K*b[i];
		printf("%d ",d[i]);
	}
	printf("\n");*/
//	for(int i=0;i<N;i++) printf("%d ",d[i]);
//	printf("\n");
	for(int i=0;i<200200;i++) for(int j=0;j<110;j++) dp[i][j]=-inf;
	dp[NUM][0]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<200200;j++){
			dp[j][i+1]=max(dp[j][i+1],dp[j][i]);
			int nj=j+d[i];
			if(nj<0||nj>=200200) continue;
			if(dp[j][i]==-inf) continue;
			dp[nj][i+1]=max(dp[nj][i+1],dp[j][i]+a[i]);
		}
	}
	if(dp[NUM][N]==0){
		printf("-1\n");
	}else{
		printf("%d\n",dp[NUM][N]);
	}
	return 0;
}