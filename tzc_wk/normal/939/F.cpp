#include <bits/stdc++.h>
using namespace std;
int n,k,l[115],r[115],dp[115][200015],deq[200015];
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)	cin>>l[i]>>r[i];
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=r[i];j++)	dp[i][j]=dp[i-1][j];
		int head=1,tail=0;
		for(int j=0;j<=r[i];j++){
			while(head<=tail&&deq[head]<j-(r[i]-l[i]))			head++;
			while(head<=tail&&dp[i-1][j]<dp[i-1][deq[tail]])	tail--;
			deq[++tail]=j;
			dp[i][j]=min(dp[i][j],dp[i-1][deq[head]]+2);
		}
		head=1,tail=0;
		for(int j=r[i];j>=0;j--){
			while(head<=tail&&deq[head]<l[i]-j)						head++;
			while(head<=tail&&dp[i-1][r[i]-j]<dp[i-1][deq[tail]])	tail--;
			deq[++tail]=r[i]-j;
			dp[i][j]=min(dp[i][j],dp[i-1][deq[head]]+1);
		}
	}
	if(dp[k][n]>=0x3f3f3f3f)	puts("Hungry");
	else						puts("Full"),cout<<dp[k][n]<<endl;
}