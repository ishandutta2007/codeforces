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

int n;
long long ans;
bool found = false;
vector<pair<int, int>> arr; 

int main() {
	srand(time(0));
    //read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n;
    for (int i = 0; i < n; ++i) {
        int coor;
        char f;
        cin >> coor >> f;
        if (f == 'G') {
            found = true;
            arr.pb({coor, 0});
        } else if (f == 'R') {
            arr.pb({coor, 1});
        } else {
            arr.pb({coor, 2});
        }
    }
    if (!found) {
        for (int t = 1; t < 3; ++t) {
            vector<int> p;
            for (auto i : arr) {
                if (i.y == t) {
                    p.pb(i.x);
                }
            }
            if (p.size() > 1) {
                ans += p.back() - p[0];
            }
        }
    } else {
        int Ln = 0, Rn = n - 1;
        while (arr[Ln].y) ++Ln;
        while (arr[Rn].y) --Rn;
        for (int t = 1; t < 3; ++t) {
            for (int i = 0; i < Ln; ++i)  {
                if (arr[i].y == t) {
                    ans += abs(arr[Ln].x - arr[i].x);
                    break;
                }
            }
            for (int i = n - 1; i > Rn; --i)  {
                if (arr[i].y == t) {
                    ans += abs(arr[Rn].x - arr[i].x);
                    break;
                }
            }
        }
        int L = Ln;
        while (L != Rn) {
            long long f1 = 0;
            vector<int> coor[2];
            coor[0].pb(arr[L].x);
            coor[1].pb(arr[L].x);
            int R = L + 1;
            while (arr[R].y) {
                coor[arr[R].y - 1].pb(arr[R].x);
                ++R;
            }
            coor[0].pb(arr[R].x);
            coor[1].pb(arr[R].x);
            f1 += arr[R].x - arr[L].x;
            for (int t = 0; t < 2; ++t) {
                int maxd = 0;
                for (int i = 0; i + 1 < coor[t].size(); ++i) {
                    chkmax(maxd, coor[t][i + 1] - coor[t][i]);
                }
                f1 += arr[R].x - arr[L].x - maxd;
            }
            if (coor[0].size() > 2 && coor[1].size() > 2) {
                chkmin(f1, (arr[R].x - arr[L].x) * 2);
            }
            ans += f1;
            L = R;
        }
    }
    cout << ans << endl;
}