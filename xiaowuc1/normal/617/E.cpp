#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
	int l, r, idx;
	int64_t ord;
  Query() {}
  Query(int lhs, int rhs, int idxidx) {
    l = lhs;
    r = rhs;
    idx = idxidx;
    calcOrder();
  }
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}
ll ret[100005];
int dp[2000005];

void solve() {
  int n, q, x;
  cin >> n >> q >> x;
  vector<int> pref;
  pref.push_back(0);
  for(int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    pref.push_back(t ^ pref[i-1]);
  }
  vector<Query> query;
  query.resize(q);
  for(int i = 0; i < q; i++) {
    int lhs, rhs;
    cin >> lhs >> rhs;
    query[i] = Query(lhs, rhs, i);
  }
  sort(query.begin(), query.end());
  ll curr = 0;
  for(int a = query[0].l; a <= query[0].r; a++) {
    curr += dp[pref[a]^x];
    dp[pref[a]]++;
  }
  ret[query[0].idx] = curr + dp[pref[query[0].l-1]^x];
  for(int i = 1; i < query.size(); i++) {
    // add lhs
    for(int a = query[i].l; a < query[i-1].l; a++) {
      curr += dp[pref[a]^x];
      dp[pref[a]]++;
    }
    // subtract lhs
    for(int a = query[i-1].l; a < query[i].l; a++) {
      dp[pref[a]]--;
      curr -= dp[pref[a]^x];
    }
    // subtract rhs
    for(int a = query[i].r + 1; a <= query[i-1].r; a++) {
      dp[pref[a]]--;
      curr -= dp[pref[a]^x];
    }
    // add rhs
    for(int a = query[i-1].r+1; a <= query[i].r; a++) {
      curr += dp[pref[a]^x];
      dp[pref[a]]++;
    }
    ret[query[i].idx] = curr + dp[pref[query[i].l-1]^x];
  }
  for(int i = 0; i < q; i++) cout << ret[i] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}