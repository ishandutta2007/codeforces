#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif

struct UnionFind {
	vector<int> par;
	vector<int> siz;
	UnionFind(int N) {
		par.resize(N);
		siz.resize(N);

		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;
		}
	}
	int operator[](const int &x) {
		return getParent(x);
	}
	int getParent(int x) {
		if (par[x] == x) {
			return x;
		}

		return par[x] = getParent(par[x]);
	}
	int getSize(const int &x) {
		return siz[getParent(x)];
	}
	bool merge(int x, int y) {
		x = getParent(x);
		y = getParent(y);

		if (x == y) {
			return false;
		}

		if (siz[x] > siz[y]) {
			swap(x, y);    // siz[x] is smaller
		}

		par[x] = y;
		siz[y] += siz[x];
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};

/*input
4
4 5 7
4 1 3
1 2 5
2 3 8
2 4 1
3 4 4
4 6 5
1 2 1
1 3 1
1 4 2
2 4 1
4 3 1
3 2 1
3 2 10
1 2 8
1 3 10
5 5 15
1 2 17
3 1 15
2 3 10
1 4 14
2 5 8

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long n, m, k;
		cin >> n >> m >> k;
		vector<pair<long long, pair<int, int>>> did, maz;

		for (int i = 0; i < m; ++i) {
			long long a, b, c;
			cin >> a >> b >> c;
			a--, b--;

			if (c <= k) {
				maz.push_back({c, {a, b}});
			}
			else {
				did.push_back({c, {a, b}});
			}
		}

		sort(maz.begin(), maz.end());
		sort(did.begin(), did.end());

		long long ans = 10000000000000000ll;
		{
			UnionFind par(n);
			long long kaina = 10000000000000000ll;
			long long kaina2 = 0;
			bool du = false;

			for (int i = (int)maz.size() - 1; i >= 0; --i) {
				long long a = maz[i].second.first, b = maz[i].second.second, c = maz[i].first;

				if (par.merge(a, b)) {
					kaina = min(kaina, abs(k - c));
				}
			}

			for (int i = 0; i < (int)did.size(); ++i) {
				long long a = did[i].second.first, b = did[i].second.second, c = did[i].first;

				if (par.merge(a, b)) {
					du = true;
					kaina2 += abs(k - c);
				}
			}

			if (du) {
				kaina = kaina2;
			}

			ans = kaina;
		}
		{
			UnionFind par(n);
			long long kaina = 10000000000000000ll;
			long long kaina2 = 0;
			bool du = false;

			if (did.size()) {
				int i = 0;
				long long a = did[i].second.first, b = did[i].second.second, c = did[i].first;

				if (par.merge(a, b)) {
					du = true;
					kaina2 += abs(k - c);
				}
			}

			for (int i = (int)maz.size() - 1; i >= 0; --i) {
				long long a = maz[i].second.first, b = maz[i].second.second, c = maz[i].first;

				if (par.merge(a, b)) {
					kaina = min(kaina, abs(k - c));
				}
			}

			for (int i = 1; i < (int)did.size(); ++i) {
				long long a = did[i].second.first, b = did[i].second.second, c = did[i].first;

				if (par.merge(a, b)) {
					du = true;
					kaina2 += abs(k - c);
				}
			}

			if (du) {
				kaina = kaina2;
			}

			ans = min(ans, kaina);
		}

		cout << ans << "\n";
	}

}