#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x[10000],len,dp[1001000];
void find(int k1){
	if (k1>n) return;
	x[++len]=k1; find(k1*10+1); find(k1*10);
}
void print(int n){
	if (n==0) return;
	for (int i=1;i<=len;i++) if (x[i]<=n&&dp[n]==dp[n-x[i]]+1){
		printf("%d ",x[i]); print(n-x[i]); return;
	}
}
int main(){
	scanf("%d",&n); find(1);
	memset(dp,0x3f,sizeof dp); dp[0]=0;
	for (int i=1;i<=len;i++)
		for (int j=x[i];j<=n;j++) dp[j]=min(dp[j],dp[j-x[i]]+1);
	printf("%d\n",dp[n]);
	print(n);
}