#include <bits/stdc++.h>
using namespace std;
int dp[503][503]={0};
int a[503];
int f(int i,int j){
    if(i>=j)	return 1;
    if(dp[i][j])	return dp[i][j];
    int ans=1e9;
    if(a[i]==a[j])	ans=min(ans,f(i+1,j-1));
    for(int k=i;k<j;k++)	ans=min(ans,f(i,k)+f(k+1,j));
    return dp[i][j]=ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",&a[i]);
	printf("%d\n",f(0,n-1));
	return 0;
}