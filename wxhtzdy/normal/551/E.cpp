#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 500005;
const int B = 720;

int n, q;
int a[N];
ll lzy[N];
vector<pii> b[B];

void updateBlock(int id, int l, int r, int x) {
	for (int j = 0; j < b[id].size(); j++) {
		if (l <= b[id][j].se && b[id][j].se <= r) {
			b[id][j].fi += x;
		}
	}
	sort(all(b[id]));
}

pii queryBlock(int id, ll val) {
	val -= lzy[id];
	if (b[id].empty()) return {n, -1};
	if (b[id][0].fi > val || b[id].back().fi < val) return {n, -1};
	pii ret = {-1, -1};
	int sz = b[id].size();
	{
		int low = 0, high = sz - 1;
		while (low <= high) {
			int mid = low + high >> 1;
			if (b[id][mid].fi >= val) {
				if (b[id][mid].fi == val) {
					ret.fi = b[id][mid].se;
				}
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
	}
	{
		int low = 0, high = sz - 1;
		while (low <= high) {
			int mid = low + high >> 1;
			if (b[id][mid].fi <= val) {
				if (b[id][mid].fi == val) {
					ret.se = b[id][mid].se;
				}
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
	}
	if (ret.fi == -1 || ret.se == -1) ret = {n, -1};
	return ret;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		b[i / B].pb({a[i], i});
	}
	for (int i = 0; i < B; i++) {
		sort(all(b[i]));
	}
	while(q--) {
		int typ;
		scanf("%d", &typ);
		if (typ == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			--l; --r;
			for (int i = 0; i < B; i++) {
				int L = i * B;
				int R = (i + 1) * B - 1;
				if (l <= L && R <= r) {
					lzy[i] += x;
				} else {
					if (R < l || r < L) continue;
					updateBlock(i, l, r, x);
				}
			}
		} else {
			int y;
			scanf("%d", &y);
			int L = n;
			int R = -1;
			for (int i = 0; i < B; i++) {
				pii Q = queryBlock(i, y);
				L = min(L, Q.fi);
				R = max(R, Q.se);
			}
			//printf("%d %d\n", L, R);
			if (R == -1) printf("-1\n");
			else printf("%d\n", R - L);
		}
	}
	return 0;
}