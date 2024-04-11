//Binary search + dp
#include <bits/stdc++.h>
using namespace std;
int n,a[1005],dp[1005][260],ans,lst[1005][1005],track[8][1005],cnt[8];
int check(int len){
	for(int i=1;i<=n;i++){
		int A=lst[i][len-1],B=lst[i][len-2];
		for(int j=0;j<256;j++){
			dp[i][j]=dp[i-1][j];
			if(!(j&(1<<a[i]))) continue;
			int k=j-(1<<a[i]);
			if(A&&dp[A-1][k]>-INT_MAX)	dp[i][j]=max(dp[i][j],dp[A-1][k]+len);
			if(B&&dp[B-1][k]>-INT_MAX)	dp[i][j]=max(dp[i][j],dp[B-1][k]+len-1);
        }
    }
    return dp[n][255];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
		a[i]--;
		lst[i][0]=i;
		int *now=track[a[i]];
        for(int j=1;j<=n;j++){
			if(j<=cnt[a[i]])	lst[i][j]=now[cnt[a[i]]-j+1];
			else				lst[i][j]=0;
		}
        now[++cnt[a[i]]]=i;
    }
    for(int i=0;i<8;i++)
		if(cnt[i])
			ans++;
    for(int j=1;j<256;j++)	dp[0][j]=-INT_MAX;
    int L=2,R=n;
    while(L<=R){
        int mid=(L+R)>>1;
        if(check(mid)>-INT_MAX)	L=mid+1;
		else					R=mid-1;
    }
    cout<<max(ans,check(R))<<endl;
    return 0;
}