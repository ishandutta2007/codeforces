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
  
typedef int base;
typedef pair<base, base> point;

const string FILENAME = "input";

const int MAXN = 1 << 19;

int cnt = 1;
vector<int> a[30];
int used[MAXN * 2];

void clearing(int k) {
	vector<int> b;
	for (int i : a[k + 1]) {
		if (i == 0) continue;
		if (used[i + MAXN] != cnt) {
			b.pb(i);
			used[i + MAXN] = cnt;
		}	
	}
	swap(b, a[k + 1]);
	++cnt;
}

int ans = 30;
vector<int> rep;

vector<int> cur;

void res(int k) {
	if (a[k].size() == 0) {
		if (cur.size() < ans) {
			ans = cur.size();
			rep = cur;
		}
		return;
	}
	if (k == 21) return;
	bool need = false;
	for (int i : a[k]) {
		if (i & 1) {
			need = true;
			break;
		}
	}
	for (int i = -1; i <= 1; ++i) {
		if ((i & 1) != need) continue;
		if (i) cur.pb(i * (1 << k));
		for (int j : a[k]) {
			if (j & 1) {
				a[k + 1].pb((j - i) / 2);
			} else {
				a[k + 1].pb(j / 2);
			}
		}
		clearing(k);
		res(k + 1);
		if (i) cur.pop_back();
		a[k + 1].clear();
	}
}

int n;

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		a[0].pb(v);
	}
	res(0);
	cout << ans << endl;
	for (int i : rep) cout << i << ' ';
	cout << endl;
}