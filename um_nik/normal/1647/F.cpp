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

const int INF = (int)1e9 + 7;
const int N = 500500;
int n;
int a[N];
pii ord[N];
int ans;
int L, R;
int pref[N][2];
int suf[N][2];
int leftVal = -1, rightVal = -1;
bool incOk = true, decOk = true;
int dp[N][2];

void addLeft(int x) {
	if (leftVal == -1) {
		leftVal = rightVal = x;
		return;
	}
	incOk &= x < leftVal;
	decOk &= x > leftVal;
	leftVal = x;
}
void addRight(int x) {
	if (rightVal == -1) {
		leftVal = rightVal = x;
		return;
	}
	incOk &= rightVal < x;
	decOk &= rightVal > x;
	rightVal = x;
}
bool tryLeft(int p) {
	if (!decOk) return false;
	if (a[p] < pref[p][1]) return false;
	for (int i = p; i <= L; i++) {
		dp[i][0] = -INF;
		dp[i][1] = INF;
	}
	if (a[p] < pref[p][0]) {
		dp[p][1] = pref[p][0];
	} else {
		dp[p][1] = pref[p][1];
	}
	for (int i = p + 1; i <= L; i++) {
		if (a[i - 1] < a[i])
			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		if (dp[i - 1][0] > a[i])
			dp[i][1] = min(dp[i][1], a[i - 1]);
		if (dp[i - 1][1] < a[i])
			dp[i][0] = max(dp[i][0], a[i - 1]);
		if (a[i - 1] > a[i])
			dp[i][1] = min(dp[i][1], dp[i - 1][1]);
	}
	int x = dp[L][0];
	if (x <= -INF) return false;
	if (leftVal != -1 && x <= leftVal) return false;
	if (leftVal != -1) x = rightVal;
	return x > suf[R + 1][1] && a[R] > suf[R + 1][0];
}
bool tryRight(int p) {
	if (!incOk) return false;
	if (a[p] < suf[p + 1][1]) return false;
	for (int i = R; i <= p; i++) {
		dp[i][0] = -INF;
		dp[i][1] = INF;
	}
	if (a[p] < suf[p + 1][0]) {
		dp[p][1] = suf[p + 1][0];
	} else {
		dp[p][1] = suf[p + 1][1];
	}
	for (int i = p - 1; i >= R; i--) {
		if (a[i + 1] < a[i])
			dp[i][0] = max(dp[i][0], dp[i + 1][0]);
		if (dp[i + 1][0] > a[i])
			dp[i][1] = min(dp[i][1], a[i + 1]);
		if (dp[i + 1][1] < a[i])
			dp[i][0] = max(dp[i][0], a[i + 1]);
		if (a[i + 1] > a[i])
			dp[i][1] = min(dp[i][1], dp[i + 1][1]);
	}
//	for (int i = p; i >= R; i--)
//		eprintf("%d %d\n", dp[i][0], dp[i][1]);
	int x = dp[R][0];
	if (x <= -INF) return false;
	if (rightVal != -1 && x <= rightVal) return false;
	if (rightVal != -1) x = leftVal;
	return x > pref[L][1] && a[L] > pref[L][0];
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ord[i] = mp(a[i], i);
	}
	sort(ord, ord + n);
	reverse(ord, ord + n);
	pref[0][0] = pref[0][1] = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] < pref[i][1]) {
			pref[i + 1][0] = pref[i + 1][1] = INF;
		} else if (a[i] < pref[i][0]) {
			pref[i + 1][0] = pref[i][0];
			pref[i + 1][1] = a[i];
		} else {
			pref[i + 1][0] = a[i];
			pref[i + 1][1] = pref[i][1];
		}
	}
	suf[n][0] = suf[n][1] = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] < suf[i + 1][1]) {
			suf[i][0] = suf[i][1] = INF;
		} else if (a[i] < suf[i + 1][0]) {
			suf[i][0] = suf[i + 1][0];
			suf[i][1] = a[i];
		} else {
			suf[i][0] = a[i];
			suf[i][1] = suf[i + 1][1];
		}
	}
	L = R = ord[0].second;
	for (int i = 1; i < n; i++) {
		//eprintf("%d\n", ans);
		int p = ord[i].second;
		if (p < L) {
			if (tryLeft(p)) ans++;
			L--;
			while(L > p) {
				addLeft(a[L]);
				L--;
			}
		} else if (R < p) {
			if (tryRight(p)) ans++;
			R++;
			while(R < p) {
				addRight(a[R]);
				R++;
			}
		} else {
			int x;
			bool ok = true;
			x = a[p];
			for (int i = p - 1; ok && i >= L; i--) {
				if (a[i] > a[p]) continue;
				if (a[i] > x) {
					ok = false;
					break;
				}
				x = a[i];
			}
			ok &= a[L] > pref[L][0];
			ok &= x > pref[L][1];
			x = a[p];
			for (int i = p + 1; ok && i <= R; i++) {
				if (a[i] > a[p]) continue;
				if (a[i] > x) {
					ok = false;
					break;
				}
				x = a[i];
			}
			ok &= a[R] > suf[R + 1][0];
			ok &= x > suf[R][1];
			ans += (int)ok;
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}