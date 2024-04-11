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

const int MAXN = 1501;
const int MAXB = MAXN / 64;

int n, k;
set<int> v;
vector<int> elem;
vector<int> chk;
vector<int> ans;

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n >> k;	
	for (int i = 1; i <= n; ++i) {
		v.insert(i);
	}
	elem.pb(1e9);
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		while (elem.back() < a) {
			chk.pb(elem.back());
			elem.pop_back();
		}
		elem.pb(a);
		ans.pb(a);
		v.erase(a);
	}
	while (elem.size() > 1 || v.size()) {
		// for (int i : ans) cout << i << ' ';
		// cout << '\n';
		if (elem.size() == 1) {
			ans.pb(*v.rbegin());
			elem.pb(*v.rbegin());
			v.erase(*v.rbegin());
		} else {
			auto it = v.lower_bound(elem.back());
			if (it == v.begin()) {
				chk.pb(elem.back());
				elem.pop_back();
			} else {
				--it;
				ans.pb(*it);
				elem.pb(*it);
				v.erase(it);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (chk[i] != (i + 1)) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i : ans) cout << i << ' ';
	cout << '\n';
}