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
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1e6 + 1;

int n, m;
int a, b;
int L = 1, R = 1e5;

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	srand(time(0));
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a, --b;
		while ((a / L) > b) {
			++L;
		}
		while ((a / R) < b) {
			--R;
		}
	}
	--n;
	//cout << L << ' ' << R << endl;
	int Ln = n / L, Rn = n / R;
	if (Ln != Rn) {
		cout << -1 << endl;
	} else {
		cout << Ln + 1 << endl;
	}
}