#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector

int a[1005];
void solve() {
	int n; cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	vt<int> cnt = {count(a, a+n, 0), count(a, a+n, 1)};
	if(cnt[1]>n/2) {
		cout << cnt[1]-(cnt[1]&1) << "\n";
		for(int i=0;i<cnt[1]-(cnt[1]&1);i++)
			cout<< 1 << " ";
	} else {
		cout << cnt[0] << "\n";		
		for(int i=0;i<cnt[0];i++)
			cout << 0 << " ";
	}
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}