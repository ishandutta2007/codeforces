#include <bits/stdc++.h>
using namespace std;

const int M = 105;
map<int,int> mp;
int N, S, T, i, j, k, mat[M][M], a[M][M], o[M][M], arr[M];
vector<int> msk;
int LIS(int x,int y){
	int dp[M], ans=0;
	for(int i=1;i<=N;i++){
		if(arr[i]<x||arr[i]>y) continue;
		if(ans==0||arr[i]>=dp[ans-1]) dp[ans++]=arr[i];
		else{
			int p = upper_bound(dp,dp+ans,arr[i])-dp;
			dp[p] = arr[i];
		}
	}
	return ans;
}
void cpy(){
	for(int i=1;i<=S;i++){
		for(int j=1;j<=S;j++)
			mat[i][j] = a[i][j];
	}
}
void mul(int b=0){
	memset(a,0,sizeof(a));
	for(int i=1;i<=S;i++){
		for(int j=i;j<=S;j++){
			for(int k=i;k<=j;k++){
				if(b) a[i][j]=max(a[i][j],mat[i][k]+o[k][j]);
				else a[i][j]=max(a[i][j],mat[i][k]+mat[k][j]);
			}
		}
	}
}
int main(){
	for(scanf("%d%d",&N,&T),i=1;i<=N;i++)
		scanf("%d",&arr[i]), mp[arr[i]]=0;
	i=0; auto it=mp.begin();
	for(;it!=mp.end();it++) it->second=++i;
	while(T){
		msk.insert(msk.begin(),T&1);
		T >>= 1;
	}
	for(i=1;i<=N;i++) arr[i] = mp[arr[i]];
	S = mp.size();
	for(j=1;j<=S;j++){
		for(k=j;k<=S;k++)
			o[j][k]=LIS(j,k);
	}
	for(auto v : msk){
		mul(); cpy();
		if(v) mul(1), cpy();
	}
	printf("%d\n",mat[1][S]);
	return 0;
}