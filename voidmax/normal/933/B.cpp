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
  
typedef pair<int, int> point;

const string FILENAME = "input";

const int MAXN = 2018;

long long p;
int k;

vector<int> ans;

int get(long long p, int k) {
	int r = p % k;
	if (r < 0) r += k;
	return r;
}

void test(long long p, int k) {
	if (p == 0) {
		return;
	} 
	assert(ans.size() < 1e5);
	ans.pb(get(p, k));
	test(-((p - get(p, k)) / k), k);
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> p >> k;
	test(p, k);
	cout << ans.size() << endl;
	for (int i : ans) cout << i << ' ';
	cout << endl;
}