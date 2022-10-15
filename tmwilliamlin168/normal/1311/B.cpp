#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100], p[100];

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<m; ++i) {
		cin >> p[i];
	}
	sort(p, p+m);
	for(int i=0, j=0; i<m; i=j) {
		for(; j<m&&p[j]-p[i]==j-i; ++j);
		//cout << i << " " << j << endl;
		sort(a+p[i]-1, a+p[j-1]+1);
	}
	for(int i=0; i+1<n; ++i)
		if(a[i]>a[i+1]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}