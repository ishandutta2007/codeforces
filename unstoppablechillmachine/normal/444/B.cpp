#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
ll x;
int n, d;
int a[N], b[N];

ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

void initAB() {
	for (int i = 0; i < n; i = i + 1) {
		a[i] = i + 1;
	}
	for (int i = 0; i < n; i = i + 1) {
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for (int i = 0; i < n; i = i + 1) {
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (int i = 0; i < n; i = i + 1) {
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}

const int B = 1000;

signed main() {
	cin >> n >> d >> x;
	initAB();
	int cnt = 0;
	vector<int> ones;
	set<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			cnt++;
			ones.pb(i);
		}
		st.insert({-a[i], i});
		int cur = 0;
		if (cnt < B) {
			for (int x : ones) {
				cur = max(cur, a[i - x]);
			}
			cout << cur << '\n';
		}
		else {
			int cur = 0;
			for (auto it : st) {
				if (b[i - it.S]) {
					cur = -it.F;
					break;
				}
			}
			cout << cur << '\n';
		}
	}
}