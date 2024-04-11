#include <bits/stdc++.h>
using namespace std;
int n,a[1005];
int dp[1005][1005];//dp[i][j] means choose one out of i,i+1,j
int dfs(int i,int j){
	if(dp[i][j])	return dp[i][j];
	if(i>n)			return dp[i][j]=a[j];
	if(i==n)		return dp[i][j]=max(a[i],a[j]);
	int A=max(a[i],a[j])+dfs(i+2,i+1);
	int B=max(a[i+1],a[j])+dfs(i+2,i);
	int C=max(a[i],a[i+1])+dfs(i+2,j);
	return dp[i][j]=min(A,min(B,C));
}
void print(int i,int j){
	if(i==n){
		cout<<j<<" "<<i<<endl;
		return;
	}
	if(i>n){
		cout<<j<<endl;
		return;
	}
	int val=dp[i][j];
	if(val==max(a[i],a[i+1])+dp[i+2][j]){
		cout<<i<<" "<<i+1<<endl;
		print(i+2,j);
	}
	else if(val==max(a[i+1],a[j])+dp[i+2][i]){
		cout<<j<<" "<<i+1<<endl;
		print(i+2,i);
	}
	else if(val==max(a[i],a[j])+dp[i+2][i+1]){
		cout<<j<<" "<<i<<endl;
		print(i+2,i+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	cout<<dfs(2,1)<<endl;//1,2,3
	print(2,1);
	return 0;
}