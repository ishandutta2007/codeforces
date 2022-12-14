#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=1<<29;

int ps[3030];
int dp[3030][3030];

int N,K;

int rhund=-1,rnonzero=-1;

bool exist_hund(int l){
	if(rhund==-1) return false;
	if(rhund<l) return false;
	return true;
}

bool exist_nonzero(int l){
	if(rnonzero==-1) return false;
	if(rnonzero<l) return false;
	return true;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",ps+i);
		if(ps[i]==100) rhund=i;
		if(ps[i]!=0) rnonzero=i;
	}
	for(int i=0;i<3030;i++) for(int j=0;j<3030;j++) dp[i][j]=inf;
	dp[0][1]=0;
	for(int j=1;j<N;j++){
		for(int i=0;i<j;i++){
			int cur=dp[i][j];
			if(ps[i]!=0&&exist_hund(j)==false){
				dp[i][j+1]=min(dp[i][j+1],cur+1);
			}
			if(ps[i]!=0&&exist_nonzero(j)){
				dp[j+1][j+2]=min(dp[j+1][j+2],cur+1);
			}
			if(ps[i]!=100&&exist_nonzero(j)){
				dp[j][j+1]=min(dp[j][j+1],cur+1);
			}
		}
	}
	int ans=0;
//	for(int i=0;i<=N;i++){
//		for(int j=0;j<=N+1;j++) printf("%d ",dp[i][j]);
//		printf("\n");
//	}
	for(int i=0;i<=N;i++) for(int j=0;j<=N+1;j++){
		if(dp[i][j]<=K) ans++;
	}
	printf("%d\n",ans);
	return 0;
}