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

string a, b;
int cnt[3];

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> a;
	b = a;
	sort(a.begin(), a.end());
	if (a != b) {
		cout << "NO" << endl;
	} else {
		for (auto i : a) {
			cnt[i - 'a']++; 
		}
		if (cnt[0] == 0 || cnt[1] == 0) {
			cout << "NO" << endl;
			return 0;
		}
		if (cnt[0] != cnt[2] && cnt[1] != cnt[2]) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
	}
}