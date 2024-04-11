#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int a,b,h,w,n,L,R;
int A[110000],B[110000];
struct atom{
	int where,w;
}x[110000];
int len;
int dp[50][110000];
void update(int &k1,int k2){
	k1=min(k1,k2);
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1,greater<int>());
	L=(a-1)/h+1,R=(b-1)/w+1;
	memset(dp,0x3f,sizeof dp);
	dp[0][L]=R; int ans=1e9;
	for (int i=1;i<=n+1;i++){
	//	cout<<"asd "<<A[i]<<endl;
		if (dp[i-1][1]==1){
			ans=min(ans,i-1); break;
		}
		if (i>n) break;
		for (int j=1;j<=L;j++)
			if (dp[i-1][j]<1e9){
			//	cout<<"fa "<<i<<" "<<j<<" "<<dp[i-1][j]<<endl;
				update(dp[i][(j-1)/A[i]+1],dp[i-1][j]);
				update(dp[i][j],(dp[i-1][j]-1)/A[i]+1);
			}
	}
	memset(dp,0x3f,sizeof dp);
	L=(a-1)/w+1,R=(b-1)/h+1;
	dp[0][L]=R;
	for (int i=1;i<=n+1;i++){
		if (dp[i-1][1]==1){
			ans=min(ans,i-1); break;
		}
		if (i>n) break;
		for (int j=1;j<=L;j++)
			if (dp[i-1][j]<1e9){
				update(dp[i][(j-1)/A[i]+1],dp[i-1][j]);
				update(dp[i][j],(dp[i-1][j]-1)/A[i]+1);
			}
	}
	if (ans>1e8) ans=-1;
	cout<<ans<<endl;
}