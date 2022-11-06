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
typedef pair<long double, long double> point;
typedef long double base;

const int MAXN = 101;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, r;
vector<point> ans;

int main() {
	srand(time(0));
    //read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n >> r;
    //dx**2 + dy**2 = r**2
    for (int i = 0; i < n; ++i) {
        point res = {1e18, r};
        cin >> res.x;
        for (int j = 0; j < i; ++j) {
            long long w = abs(res.x - ans[j].x);
            if (w * w <= 4 * r * r) {
                chkmax(res.y, ans[j].y + sqrt(abs(4 * r * r - w * w)));
            }
        } 
        ans.pb(res);
        cout << setprecision(10) << fixed << res.y << ' '; 
    }   
    cout << '\n';
}