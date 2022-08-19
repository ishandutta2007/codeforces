#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

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
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = (int)1e6 + 77;
const int M = 65;
char s[N];
short dp[N][M];
int n;

void solveDP() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < M; j++)
			dp[i][j] = -1;
	dp[0][0] = 0;
	for (int l = 0; l < n; l++) {
		if (s[l] == '0') {
			for (int x = 0; x < M; x++)
				if (dp[l][x] != -1) {
					dp[l + 1][x] = 1;
				}
			continue;
		}
		int cur = 0;
		for (int r = l; r < n; r++) {
			cur <<= 1;
			if (s[r] == '1') cur++;
			if (cur >= M) break;
			for (int x = 0; x + cur < M; x++) {
				if (dp[l][x] != -1) {
					dp[r + 1][x + cur] = r - l + 1;
				}
			}
		}
	}
	int sum = 1;
	while(sum < M && dp[n][sum] == -1) sum <<= 1;
	if (sum >= M) {
		printf("-1\n");
		return;
	}
	vector<pii> ans;
	int p = n;
	while(p > 0) {
		int x = dp[p][sum];
		ans.push_back(mp(p - x, p));
		p -= x;
		int y = 0;
		for (int i = p; i < p + x; i++) {
			y <<= 1;
			if (s[i] == '1') y++;
		}
		sum -= y;
	}
	reverse(all(ans));
	assert(sum == 0);
	printf("%d\n", (int)ans.size());
	for (pii t : ans)
		printf("%d %d\n", t.first + 1, t.second);
}

void solve() {
	scanf("%s", s);
	n = strlen(s);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (int)(s[i] - '0');
	}
	if (sum == 0) {
		printf("-1\n");
		return;
	}
	if ((sum & (sum - 1)) == 0) {
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			printf("%d %d\n", i, i);
		return;
	}
	vector<pii> segm;
	int l = 0;
	while(l < n) {
		if (s[l] == '0') {
			l++;
			continue;
		}
		int r = l;
		while(r < n && s[r] == '1') r++;
		segm.push_back(mp(l, r));
		l = r;
	}
	int k = (int)segm.size();
	if (k == 1) {
		vector<pii> ans;
		if (s[0] == '0') ans.push_back(mp(0, segm[0].first));
		ans.push_back(mp(segm[0].first, segm[0].first + 1));
		ans.push_back(mp(segm[0].first + 1, segm[0].second));
		if (s[n - 1] == '0') ans.push_back(mp(segm[0].second, n));
		printf("%d\n", (int)ans.size());
		for (pii t : ans)
			printf("%d %d\n", t.first + 1, t.second);
		return;
	}
	if (k == 2 && (segm[0].second - segm[0].first == 1 || segm[1].second - segm[1].first == 1)) {
		vector<pii> ans;
		if (s[0] == '0') ans.push_back(mp(0, segm[0].first));
		ans.push_back(segm[0]);
		ans.push_back(mp(segm[0].second, segm[1].first));
		ans.push_back(segm[1]);
		if (s[n - 1] == '0') ans.push_back(mp(segm[1].second, n));
		printf("%d\n", (int)ans.size());
		for (pii t : ans)
			printf("%d %d\n", t.first + 1, t.second);
		return;
	}
	if (sum < 32) {
		solveDP();
		return;
	}
	int t = 0;
	while(sum > (1 << t)) t++;
	sum = (1 << t) - sum;
	vector<pii> ans;
	l = 0;
	while(l < n) {
		if (sum == 0 || s[l] == '0') {
			ans.push_back(mp(l, l + 1));
			l++;
			continue;
		}
		int cur = 1;
		int cnt = 1;
		int r = l + 1;
		while(r < n && 2 * cur - cnt <= sum) {
			cur *= 2;
			if (s[r] == '1') {
				cur++;
				cnt++;
			}
			r++;
		}
		sum -= cur - cnt;
		ans.push_back(mp(l, r));
		l = r;
	}
	assert(sum == 0);
	printf("%d\n", (int)ans.size());
	for (pii t : ans)
		printf("%d %d\n", t.first + 1, t.second);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}