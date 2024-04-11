#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2e5+5;
int T, N, i, j, x, y, arr[MN], dp[MN][2];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
			arr[i] += arr[i-1];
		}
		dp[0][0] = 0;
		dp[0][1] = 1<<30;
		for(i=1;i<=N;i++){
			for(j=0;j<2;j++){
				dp[i][j] = 1<<30;
				for(int k=1;k<=min(i,2);k++){
					int cost = 0;
					if(j) cost = arr[i]-arr[i-k];
					dp[i][j] = min(dp[i][j],dp[i-k][!j]+cost);
				}
			}
		}
		printf("%d\n",min(dp[N][0],dp[N][1]));
	}
	return 0;
}