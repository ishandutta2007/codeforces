#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int n, dp[MN][MN], i, arr[MN];

int cmp(int x, int y){
	if(y-x<0) return 0;
	else if(y-x==0) return 1;
	else if(dp[x][y]) return dp[x][y];
	if(arr[x]==arr[x+1]) dp[x][y]=min(cmp(x+1,y),cmp(x+2,y))+1;
	else dp[x][y] = cmp(x+1,y)+1;
	for(int i=x+2;i<=y;i++){
		if(arr[i]==arr[x])
			dp[x][y]=min(dp[x][y],cmp(x+1,i-1)+cmp(i+1,y));
	}
	return dp[x][y];
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",cmp(1,n));
	return 0;
}