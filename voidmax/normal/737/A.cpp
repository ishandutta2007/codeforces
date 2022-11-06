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
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
 
const string FILENAME = "input";
typedef long long base;
 
int n, k, s, t;
vector <pair <int, int>> cars;
vector <int> check_point;
 
bool check(int v) {
    int sumt = 0, last_coor = 0;
    for (int i: check_point) {
        if (i - last_coor > v)
            return false;
        int cnt = v;
        sumt += i - last_coor;
        cnt -= i - last_coor;
        sumt += max(0, i - last_coor - cnt);
        last_coor = i;
    }
    //cout << v << ' ' << sumt << endl;
    return sumt <= t;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n >> k >> s >> t;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cars.pb({a, b});
    }
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        check_point.pb(a);
    }
    check_point.pb(0);
    check_point.pb(s);
    sort(check_point.begin(), check_point.end());
    int L = -1, R = 1e9 + 1;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    int ans = 1e9 + 1;
    for (auto i: cars) {
        if (i.y >= R) {
            chkmin(ans, i.x);
        }
    }
    if (ans == 1e9 + 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}