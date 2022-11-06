// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
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
  
typedef long double base;
typedef pair<base, base> point;

const string FILENAME = "input";
const int MAXN = 1e6 + 1;

int n, a, b;
int way[MAXN * 2];

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> a >> b;
	way[0] = -1;
	for (int i = 0; i < n; ++i) {
		if (way[i]) {
			way[i + a] = a;
			way[i + b] = b;
		}
	}
	if (!way[n]) {
		cout << "-1" << endl;
		return 0;
	}
	int clr = 1;
	while (n > 0) {
		int c = way[n];
		vector<int> arr;
		for (int i = 1; i < c; ++i) {
			cout << clr + i << ' ';
		}
		cout << clr << ' ';
		clr += c;
		n -= c;
	}
	cout << endl;
}