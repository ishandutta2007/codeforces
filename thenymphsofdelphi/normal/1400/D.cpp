#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

long long a[3005], mid[3005], suf[3005];

void solve(){
	long long n; cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	long long ans = 0;
	for (long long i = 1; i <= n - 1; i++){
		for (long long j = 1; j <= n; j++){
			mid[j] = 0; suf[j] = 0;
		}
		for (long long j = i + 2; j <= n; j++) suf[a[j]]++;
		long long cur = 0;
		for (long long j = i + 2; j <= n; j++){
			cur -= mid[a[j]]; suf[a[j]]--; mid[a[j - 1]]++; cur += suf[a[j - 1]];
			if (a[i] == a[j]) ans += cur;
		}
	}
	cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}