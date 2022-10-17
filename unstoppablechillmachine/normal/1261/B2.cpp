#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.F != b.F) {
		return a.F > b.F;
	}
	else {
		return a.S < b.S;
	}
}

const int N = 2e5 + 10;
int t[N], n, on[N], ans[N];

void update(int v) {
	for (; v <= n; v += v & (-v)) {
		t[v]++;
	}
}

int get(int v) {
	int res = 0;
	for (; v > 0; v -= v & (-v)) {
		res += t[v];
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		on[i + 1] = x;
		arr.pb({x, i + 1});
	}
	sort(all(arr), cmp);
	int m;
	cin >> m;
	vector<pair<pair<int, int>, int>> que;
	for (int i = 0; i < m; i++) {
		int k, pos;
		cin >> k >> pos;
		que.pb(make_pair(make_pair(k, pos), i));
	}
	sort(all(que));
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		update(arr[i].S);
		while (ptr < m && que[ptr].F.F == i + 1) {
			int need = que[ptr].F.S;
			int l = 0, r = n + 1;
			while (r - l > 1) {
				int mid = (l + r) / 2;
				if (get(mid) >= need) {
					r = mid;
				}
				else {
					l = mid;
				}
			}
			ans[que[ptr].S] = on[r];
			ptr++;
		}
	}
	for (int i = 0;i  <m; i++) {
		cout << ans[i] << '\n';
	}
}