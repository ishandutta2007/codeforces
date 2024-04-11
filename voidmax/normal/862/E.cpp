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
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1 << 17;

int n, m, q;
long long suma, sumb;
long long a[MAXN], b[MAXN];
vector <long long> res;

void add(int i, int r) {
	if (i & 1) 
		suma += r;
}

long long myabs(long long a) {
	if (a < 0) return -a;
	return a;
}

long long get() {
	int L = lower_bound(res.begin(), res.end(), -suma) - res.begin();
	L = max(0, L - 2);
	long long ans = 1e18;
	for (int i = L; i < res.size() && i < L + 3; ++i) {
		chkmin(ans, myabs(suma + res[i]));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i & 1) {
			suma += a[i];
		} else {
			suma -= a[i];
		}
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		if (i & 1) {
			b[i] = -b[i] + b[i - 1];
		} else {
			b[i] = b[i] + b[i - 1];
		}
	}
	for (int j = 0; j <= m - n; ++j) {
		long long f = b[j + n] - b[j];
		if (j & 1) f = -f;
		res.pb(f);
	}
	sort(res.begin(), res.end());
	cout << get() << endl;
	for (int i = 0; i < q; ++i) {
		int L, R, k;
		cin >> L >> R >> k;
		add(R, k);
		add(L - 1, -k);
		cout << get() << endl;
	}
}