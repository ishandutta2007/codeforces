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

int deg[100050];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        ++deg[--x];
        ++deg[--y];
    }

    sort(deg, deg + n);

    if (deg[0] == 1 && deg[1] == 1 && deg[2] == 2 && deg[n-1] == 2) {
        cout << "bus topology" << endl;
    } else if (deg[0] == 2 && deg[n-1] == 2) {
        cout << "ring topology" << endl;
    } else if (deg[0] == 1 && deg[n-2] == 1 && deg[n-1] == n-1) {
        cout << "star topology" << endl;
    } else {
        cout << "unknown topology" << endl;
    }

    return 0;
}