#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	int a[n]; for(int &i : a) cin >> i;
	int b[n]; for(int &i : b) cin >> i;

	int pre[n];
	pre[0] = a[0] * b[0];
	for(int i=1; i<n; ++i) pre[i] = pre[i-1] + a[i] * b[i];

	int diff[n][n];
	for(int i=0; i<n; ++i) diff[i][i] = 0;

	int maxDiff = 0;

	for(int add=1; add<n; ++add){
		for(int i=0; i+add<n; ++i){
			int j = i+add;
			diff[i][j] = i+1 == j ? 0LL : diff[i+1][j-1];
			diff[i][j] += a[i] * b[j] + a[j] * b[i] - a[i] * b[i] - a[j] * b[j];
			maxDiff = max(maxDiff, diff[i][j]);
		}
	}

	cout << pre[n-1] + maxDiff;
}