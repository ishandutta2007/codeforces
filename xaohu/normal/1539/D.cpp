#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
pair<ll, ll> a[111000];
ll cnt, res; 
 
int main() {
	cin >> n;
	rep(i, 1, n) cin >> a[i].se >> a[i].fi;
	sort(a + 1, a + n + 1);
	int j = n;
	rep(i, 1, n) {
		if (a[i].fi <= cnt) {
			res += a[i].se;
			cnt += a[i].se;
		}
		else {
			while (cnt < a[i].fi && a[i].se) {
				ll eat = min(a[i].fi - cnt, a[j].se);
				res += 2 * eat;
				cnt += eat;
				a[j].se -= eat;
				if (!a[j].se) j--;
			}
			res += a[i].se;
			cnt += a[i].se;
		}
	}	
	cout << res << endl;
	return 0;
}