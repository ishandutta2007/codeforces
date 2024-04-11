#include<bits/stdc++.h>
using namespace std;

const int maxn=1<<20;
const long long INF=1e15;
long long dp[maxn];
long long a[200007],cnt[27],inv[27][27],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		cnt[a[i]]++;
		for (int j=1;j<=20;++j){
			inv[a[i]][j]+=cnt[j];
		}
	}
	for (int i=1;i<maxn;++i){
		dp[i]=INF;
	}
	dp[0]=0;
	for (int i=0;i<maxn;++i){
		for (int j=1;j<=20;++j){
			int u=1<<j-1,t=i;
			long long sum=0;
			for (int k=1;t;k++){
				if (t&1) sum+=inv[j][k];
				t>>=1;
			}
			dp[i|u]=min(dp[i|u],dp[i]+sum);
		}
	}
	cout<<dp[maxn-1]<<endl;
	return 0;
}