#include<bits/stdc++.h>
using namespace std;
int n;
int a[110000];
int b[110000];
bool dp[110][11000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		dp[0][0]=true; 
		for(int i=1;i<=n;i++){
			for(int j=0;j<=100*i;j++){
				dp[i][j]=false;
				if((j>=a[i])&&(j<=100*(i-1)+a[i])&&dp[i-1][j-a[i]]) dp[i][j]=true;
				if((j>=b[i])&&(j<=100*(i-1)+b[i])&&dp[i-1][j-b[i]]) dp[i][j]=true;
			}
		}
		int ans=1000000000,sum=0;
		for(int i=1;i<=n;i++) sum+=a[i]+b[i];
		for(int j=0;j<=100*n;j++) if(dp[n][j]) ans=min(ans,j*j+(sum-j)*(sum-j));
		sum=0;
		for(int i=1;i<=n;i++) sum+=a[i]*a[i]+b[i]*b[i];
		ans+=sum*(n-2);
		printf("%d\n",ans);
	}
	return 0;
}