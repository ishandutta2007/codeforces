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
typedef long long base;


const string FILENAME = "input";
const int MAXN = 2e5 + 1;

int n;
int a[MAXN][2];
int ans[MAXN];
vector <pair <int, int>> arr[2];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
   	cin >> n; 
   	for (int i = 0; i < n; ++i) {
   		cin >> a[i][0];
   		arr[0].pb({a[i][0], i});
   	}
   	for (int i = 0; i < n; ++i) {
   		cin >> a[i][1];
   		arr[1].pb({a[i][1], i});
   	}
   	sort(arr[0].rbegin(), arr[0].rend());
   	sort(arr[1].begin(), arr[1].end());
   	for (int i = 0; i < n; ++i) {
   		ans[arr[1][i].y] = arr[0][i].x;
   		//cout << arr[0][i].x << ' ' << arr[1][i].y << endl;
   	}
   	for (int i = 0; i < n; ++i) {
   		cout << ans[i] << ' ';
   	}
   	cout << endl;
}