#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <random>  
#include <ctime>
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 2e6 + 1;

int n, A, B;
long long ans = 1e18;
long long cnt[MAXN], mod[MAXN];

long long f1(int L, int R) {
	return mod[R] - mod[L];
}

long long f2(int L, int R) {
	return (cnt[R] - cnt[L]) - (mod[L] * (R - L));
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> A >> B;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}
	for (int i = 1; i < MAXN; ++i) {
		mod[i] = mod[i - 1] + cnt[i];
		cnt[i] += cnt[i - 1] + mod[i - 1];
	}
	for (int d = 2; d < MAXN; ++d) {
		int f = min(A / B, d - 1);
		long long res = 0;
		for (int i = 0; i + d <= MAXN; i += d) {
			res += f1(i, i + d - 1 - f) * A + f2(i + d - 1 - f, i + d - 1) * B;
		}
		chkmin(ans, res);
	}
	cout << ans << endl;
}