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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

int n, m, q;
vector<int> res;
int arr[100001];

int func(int n) {
	vector<int> p;
	long double f = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) p.pb(i);
		while (n % i == 0) n /= i;
	}
	if (n != 1) p.pb(n);
	for (int g : p) {
		long double k = 1;
		k = k - (k / g);
		f *= k;
	}
	return round(f);
}

inline int get_mod(long long a, int b) {
	if (a >= 32) {
		return 32 + ((a - 32) % b);
	}
	return a;
}

int powx(long long a, int b, int m) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = get_mod(a * ans, m);
		a = get_mod(a * a, m);
		b >>= 1;
	}
	return ans;
}

int main() {
	srand(time(0));
   	ios::sync_with_stdio(0);
   	//read(FILENAME);
   	cin >> n >> m;
   	res.pb(m);
   	while (m > 1) {
   		m = func(m);
   		res.pb(m);
   	}
   	for (int i = 0; i < n; ++i) {
   		cin >> arr[i];
   	}
   	cin >> q;
   	for (int i = 0; i < q; ++i) {
   		int L, R;
   		cin >> L >> R;
   		--L, --R;
   		R = min(R + 1, L + (int)res.size()) - 1;
   		int ans = 1;
   		for (int j = R; j >= L; --j) {
   			ans = powx(arr[j], ans, res[j - L]);
   		}
   		cout << ans % res[0] << '\n';
   	}
}