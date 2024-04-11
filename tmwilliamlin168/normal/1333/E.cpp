#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans[500][500], p=1;

void solve(int s) {
	int m=n-s;
	if(m==3) {
		ans[s][s]=p++;
		ans[s][s+2]=p++;
		ans[s][s+1]=p++;
		ans[s+2][s+1]=p++;
		ans[s+2][s]=p++;
		ans[s+1][s+1]=p++;
		ans[s+1][s+2]=p++;
		ans[s+1][s]=p++;
		ans[s+2][s+2]=p++;
		return;
	}
	for(int i=0; i<m-1; ++i)
		ans[s][s+1+i]=p++;
	ans[s][s]=p++;
	for(int i=0; i<m-1; ++i)
		ans[n-1-i][s]=p++;
	solve(s+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if(n<3) {
		cout << -1;
		return 0;
	}
	solve(0);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}