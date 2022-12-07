#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

int t, a[4], b[4];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		rep(i, 0, 3) cin >> a[i], b[i] = a[i];
		sort(b, b + 4);
		sort(a, a + 2);
		sort(a + 2, a + 4);
		if ((a[0] == b[2] && a[1] == b[3]) || (a[2] == b[2] && a[3] == b[3]))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
		
	return 0;
}