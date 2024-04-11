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
const int MAXN = 1e6 + 1;

int n, k, cnt;
int used[MAXN];

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		used[a] = true;
		if (a == k) {
			++cnt;
		}
	}
	for (int i = 0; i < k; ++i) {
		if (!used[i]) {
			++cnt;
		}
	}
	cout << cnt << endl;
}