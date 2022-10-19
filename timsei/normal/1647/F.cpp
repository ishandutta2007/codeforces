#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int INF = 2e9;

int n, A[N], dp[N][2], L[N], R[N], ans;

void solve(){
	int pos = 0;
	for(int i = 1; i <= n; ++ i) {
		if(A[i] > A[pos]) pos = i;
		L[i] = R[i] = INF;
	}
	L[0] = R[n + 1] = 0;
	for(int i = 1; i <= n; ++ i){
		if(A[i] > A[i - 1])
		L[i] = min(L[i], L[i - 1]);
		if(A[i] > L[i - 1])
		L[i] = min(L[i], A[i - 1]);
	}
	for(int i = n; i >= 1; -- i){
		if(A[i] > A[i + 1])	
		R[i] = min(R[i], R[i + 1]);
		if(A[i]> R[i + 1]) 
		R[i] = min(R[i], A[i + 1]);
	}
	dp[pos][0] = L[pos];
	for(int i = pos + 1; i <= n; ++ i){
		dp[i][0] = INF, dp[i][1] = -INF;
		if(A[i] < A[i-1])	dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if(A[i] < dp[i - 1][1])	dp[i][0] = min(dp[i][0], A[i - 1]);
		if(A[i] > A[i - 1])	dp[i][1] = max(dp[i][1], dp[i - 1][1]);
		if(A[i] > dp[i - 1][0])	dp[i][1] = max(dp[i][1], A[i - 1]);
		if(dp[i][1] > R[i])	++ ans;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
	}
	solve();
	reverse(A + 1, A + n + 1);
	solve();
	cout << ans << endl;
}