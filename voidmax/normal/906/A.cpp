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

int ans = 0;
int n;
int cnt = 26;
bool cant[26];

int main() {
   	ios::sync_with_stdio(0);
   	//read(FILENAME);
   	cin >> n;
   	for (int i = 0; i + 1 < n; ++i) {
   		char f;
   		cin >> f;
   		string s;
   		cin >> s;
   		if (f == '.') {
   			for (char j : s) {
   				cnt += cant[j - 'a'];
   				cant[j - 'a'] = true;
   				cnt -= cant[j - 'a'];
   			}
   		} else if (f == '?') {
   			if (cnt == 1) ++ans;
   			cnt += cant[s[0] - 'a'];
   			cant[s[0] - 'a'] = true;
   			cnt -= cant[s[0] - 'a'];
   		} else {
   			if (cnt == 1) ++ans;
   			set<char> used;
   			for (char j : s) used.insert(j);
   			for (char j = 'a'; j <= 'z'; ++j) {
   				if (used.count(j) == 0) {
   					cnt += cant[j - 'a'];
		   			cant[j - 'a'] = true;
		   			cnt -= cant[j - 'a'];
   				}
   			}
   		}
   	}
   	cout << ans << endl;
}