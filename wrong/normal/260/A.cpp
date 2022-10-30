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
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int main()
{
    int a, b, n;

    cin >> a >> b >> n;

    vector<int> res;
    for (int t = a; t > 0; t /= 10) {
        res.push_back(t % 10);
    }
    reverse(res.begin(), res.end());

    int m = a % b;
    for (int i = 0; i < n; ++i) {
        for (int d = 0; d <= 9; ++d) {
            if ((10 * m + d) % b == 0) {
                res.push_back(d);
                m = 0;
                break;
            }
            if (d == 9) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < (int)res.size(); ++i) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}