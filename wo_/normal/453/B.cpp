#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int mask[66];
int primes[]={2,3,5,7,11,13,17,19,23,29};
int ln=10;

int lPrimes[]={31,37,41,43,47,53,59};
int lln=7;

int dp[1<<10][8][101];
int prev[1<<10][8][101];

int a[100];

int b[100];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=60;i++){
		for(int j=0;j<ln;j++){
			if(i%primes[j]==0) mask[i]|=(1<<j);
		}
	}
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<(1<<10);i++) for(int j=0;j<=7;j++) for(int k=0;k<=N;k++){
		dp[i][j][k]=10000;
	}
	dp[0][0][0]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<(1<<10);j++) for(int k=0;k<8;k++){
			int cur=a[i];
			for(int m=1;m<=60;m++){
				if(mask[m]==0&&m!=1) continue;
				if((j&mask[m])==0){
					int nx=dp[j][k][i]+abs(m-a[i]);
					if(dp[j|mask[m]][k][i+1]>nx){
						prev[j|mask[m]][k][i+1]=m;
					}
					dp[j|mask[m]][k][i+1]=min(dp[j|mask[m]][k][i+1],nx);
				}
			}
			if(k!=7){
				int x=lPrimes[k];
				int nx=dp[j][k][i]+(x-a[i]);
				if(dp[j][k+1][i+1]>nx){
					prev[j][k+1][i+1]=lPrimes[k];
				}
				dp[j][k+1][i+1]=min(dp[j][k+1][i+1],nx);
			}
		}
	}
	int ans=-1;
	int ci=-1,cj=-1;
	for(int i=0;i<(1<<10);i++) for(int j=0;j<8;j++){
		if(ans==-1||ans>dp[i][j][N]){
			ci=i,cj=j;
			ans=dp[i][j][N];
		}
	}
	for(int k=N;k>=1;k--){
		int cur=prev[ci][cj][k];
		if(mask[cur]!=0||cur==1){
			ci&=(~(mask[cur]));
			b[k-1]=cur;
		}else{
			cj--;
			b[k-1]=cur;
		}
	}
	for(int i=0;i<N;i++) printf("%d%c",b[i],i==N-1?'\n':' ');
	return 0;
}