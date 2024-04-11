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

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> ws;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++ws[x];
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --ws[x];
    }

    vector<int> ks;
    for (map<int, int>::iterator it = ws.begin(); it != ws.end(); ++it) {
        ks.push_back(it->second);
    }
    reverse(ks.begin(), ks.end());

    int ss = 0;
    for (int i = 0; i < (int)ks.size(); ++i) {
        ss += ks[i];
        if (ss > 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}