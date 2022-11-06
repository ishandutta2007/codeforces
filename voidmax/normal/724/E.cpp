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
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

const int MAXN = 1e4;

int n, c;
int p[MAXN], d[MAXN];
long long func[MAXN + 1][2];

int main(int argc, char const *argv[]) {
    srand(time(0));
    //read(FILENAME);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 1; i <= n; ++i) func[i][1] = 1e18;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j <= n; ++j) {
    		func[j][0] = func[j][1];
    		func[j][1] = 1e18;
    		//cout << func[j][0] << ' ';
    	}
    	//cout << endl;
    	for (int j = 0; j <= i; ++j) {
    		chkmin(func[j + 1][1], func[j][0] + d[i]);
    		chkmin(func[j][1], func[j][0] + (long long)c * j + p[i]);
    	}
    }
    long long ans = 1e18;
    for (int i = 0; i <= n; ++i) {
    	//cout << func[i][1] << ' ';
    	chkmin(ans, func[i][1]);
    }
    //cout << endl;
    cout << ans << endl;
}