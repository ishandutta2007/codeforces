#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int S = 202;
int res[2][S][S];
vector<pii> ANS[2][S][S];
vector<pii> cur;

void brute(int s1, int s2, int c1, int c2, int f) {
	if (c1 == 3 || c2 == 3) {
		int w = c1 - c2;
		if (w > res[f][s1][s2]) {
			res[f][s1][s2] = w;
			ANS[f][s1][s2] = cur;
		}
		return;
	}
	int mx = 23;
	if (c1 + c2 == 4) mx = 13;
	for (int x = 0; x <= mx; x++) {
		cur.push_back(mp(mx + 2, x));
		brute(s1 + mx + 2, s2 + x, c1 + 1, c2, f | (x == mx));
		cur.pop_back();
		cur.push_back(mp(x, mx + 2));
		brute(s1 + x, s2 + mx + 2, c1, c2 + 1, f | (x == mx));
		cur.pop_back();
	}
}

void precalc() {
	for (int k = 0; k < 2; k++)
		for (int x = 0; x < S; x++)
			for (int y = 0; y < S; y++)
				res[k][x][y] = -5;
	brute(0, 0, 0, 0, 0);
}

void solve() {
	int bst = -5;
	vector<pii> ans;
	int s1, s2;
	scanf("%d%d", &s1, &s2);
	if (res[0][s1][s2] > bst) {
		bst = res[0][s1][s2];
		ans = ANS[0][s1][s2];
	}
	for (int x = 0; x <= min(s1, s2); x++) {
		if (res[1][s1 - x][s2 - x] > bst) {
			bst = res[1][s1 - x][s2 - x];
			ans = ANS[1][s1 - x][s2 - x];
		}
	}
	if (bst == -5) {
		printf("Impossible\n");
		return;
	}
	int p = -1;
	for (int i = 0; i < (int)ans.size(); i++) {
		s1 -= ans[i].first;
		s2 -= ans[i].second;
		if (abs(ans[i].first - ans[i].second) == 2) p = i;
	}
	if (s1 != s2) throw;
	if (s1 != 0 && p == -1) throw;
	ans[p].first += s1;
	ans[p].second += s1;
	if (bst > 0) {
		printf("3:%d\n", 3 - bst);
	} else {
		printf("%d:3\n", bst + 3);
	}
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d:%d ", ans[i].first, ans[i].second);
	printf("\n");
}

int main()
{
	precalc();
	
	int t;
	scanf("%d", &t);
	while(t--) solve();
	
    return 0;
}