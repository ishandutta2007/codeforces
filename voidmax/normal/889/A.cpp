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
#define x first
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;
     
template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
     
const string FILENAME = "input";
     
typedef pair<double, double> point;
     
const int MAXN = 1000;
     
int n, a, cnt = 1;
set <int> room;
     
int main() {
    srand(time(0));
	//read(FILENAME);
    ios::sync_with_stdio(0);
    room.insert(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a;
    	if (room.count(a)) {
    		room.erase(a);
    	} else {
    		++cnt;
    	}
    	room.insert(i);
    }
    cout << cnt << endl;
}