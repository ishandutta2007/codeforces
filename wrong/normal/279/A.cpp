#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int turn[256][256];

int main()
{
    int x = 120, y = 120, val = 0;
    turn[x][y] = 0;

    while (x > 0) {
        for (int i = 0; i <= val / 2; ++i) {
            x += dx[val % 4];
            y += dy[val % 4];
            turn[x][y] = val;
        }
        ++val;
    }

    cin >> x >> y;
    cout << turn[x + 120][y + 120] << endl;

    return 0;
}