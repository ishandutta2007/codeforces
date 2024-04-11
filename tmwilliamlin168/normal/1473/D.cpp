#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, m, a[mxN], leftSum[mxN+1], leftMin[mxN+1], leftMax[mxN+1], rightMin[mxN+1], rightMax[mxN+1];
string s;

void solve() {
	cin >> n >> m >> s;
	for(int i=0; i<n; ++i) {
		a[i]=s[i]^'-'?1:-1;
		leftSum[i+1]=leftSum[i]+a[i];
		leftMin[i+1]=min(leftMin[i], leftSum[i+1]);
		leftMax[i+1]=max(leftMax[i], leftSum[i+1]);
	}
	rightMin[n]=rightMax[n]=0;
	for(int i=n-1; ~i; --i) {
		rightMin[i]=min(a[i]+rightMin[i+1], 0);
		rightMax[i]=max(a[i]+rightMax[i+1], 0);
	}
	for(int l, r; m--; ) {
		cin >> l >> r, --l;
		int mn=min(leftMin[l], leftSum[l]+rightMin[r]), mx=max(leftMax[l], leftSum[l]+rightMax[r]);
		cout << mx-mn+1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}