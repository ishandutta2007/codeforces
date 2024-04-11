/*


















*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(a) (int)(a).size()
#define lng(s) (int)(s).length()
#define pii pair<int,int>

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, n;
		cin >> a >> b >> n;
		int ans = max(a, b), cnt = 0;
		while (ans <= n) {
			if (a > b) b = b + a;
			else a = a + b;
			cnt++;
			ans = max(a, b);
		}
		cout << cnt << endl;
	}
	return 0;
}