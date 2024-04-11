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

int n;
int a[MAXN];
int pref[MAXN], suf[MAXN];


int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + (a[i] == 1);
		//cout << pref[i] << endl;
	}
	for (int i = n; i >= 1; --i) {
		suf[i] = suf[i + 1] + (a[i] == 2);
	}
	int ans = 0;
	for (int L = 1; L <= n; ++L) {
		int cur_ans = 0;
		int cnt_one = 0;
		for (int R = L; R <= n; ++R) {
			if (a[R] == 1) {
				++cur_ans;
			} else {
				++cnt_one;
				chkmax(cur_ans, cnt_one);
			}
			//cout << L << ' ' << R << ' ' << cur_ans << ' ' << pref[L - 1] << ' ' << suf[R + 1] << endl;
			chkmax(ans, pref[L - 1] + cur_ans + suf[R + 1]);
		}
	}
	cout << ans << endl;
}