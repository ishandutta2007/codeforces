#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int q, n, a[200000];

void solve() {
	cin >> n;
	for(int i=0, b; i<n; ++i)
		cin >> b, ++a[b-1];
	sort(a, a+n);
	int nxt=n, ans=0;
	for(int i=n-1; ~i; --i) {
		int nt=min(nxt, a[i]);
		nxt=max(nt-1, 0);
		ans+=nt;
	}
	cout << ans << "\n";
	memset(a, 0, 4*n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> q;
	while(q--)
		solve();
}