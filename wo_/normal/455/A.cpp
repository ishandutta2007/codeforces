#include<iostream>
#include<algorithm>

using namespace std;

long long dp[100100][2];

int a[100100];
int cnt[100100];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=0;i<100100;i++) for(int j=0;j<2;j++) dp[i][j]=-1;
	dp[0][0]=0;
	for(int n=0;n<100050;n++){
		dp[n+1][0]=max(dp[n][0],dp[n][1]);
		long long t=(long long)(n+1)*cnt[n+1];
		long long x=dp[n][0]>=0?dp[n][0]+t:-1;
		dp[n+1][1]=x;
	}
	cout<<max(dp[100030][0],dp[100030][1])<<"\n";
	return 0;
}