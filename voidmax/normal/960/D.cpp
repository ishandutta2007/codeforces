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
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

typedef long double base;
typedef pair<base, base> point;

const int MAXN = 10000;

int n;
long long w[64];

int get_log(long long X) {
	int ans = 0;
	while (X > 1) {
		X >>= 1;
		++ans;
	}
	return ans;
}

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			long long X, k;
			cin >> X >> k;
			int gl = get_log(X);
			w[gl] += k;
			w[gl] &= (1LL << gl) - 1;
		} else if (t == 2) {
			long long X, k;
			cin >> X >> k;
			int gl = get_log(X);
			k &= (1LL << gl) - 1;
			for (int i = gl; i < 61; ++i) {
				w[i] += k;
				w[i] &= (1LL << i) - 1;
				k <<= 1;
			}
		} else {
			long long X;
			cin >> X;
			int gl = get_log(X);
			while (X != 1) {
				cout << X << ' ';
				long long p = X - (1LL << gl) + w[gl];
				p &= (1LL << gl) - 1;
				p += (1LL << gl);
				--gl; 
				long long Y = (p >> 1);
				Y -= w[gl];
				Y &= (1LL << gl) - 1;
				Y += (1LL << gl);
				X = Y;
			} 
			cout << "1\n";
		}
	}
}