#include <bits/stdc++.h>
using namespace std;
const int mxN=2e5;
int a[mxN], b[mxN], io[mxN+1];
int cnt[3*mxN+5];
void solve() {
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		io[a[i]] = i;
	}
	for(int i=0; i<n; ++i) {
		cin >> b[i];
		int x=io[b[i]];
		cnt[x-i+mxN]++,cnt[(n-i)+x+mxN]++;
		
	}
	int mx=*max_element(cnt, cnt+(2*mxN+5));
	cout << mx;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t=1;

	while(t--) {
		solve();		
	}
}