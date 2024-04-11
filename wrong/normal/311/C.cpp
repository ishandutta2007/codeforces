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

bool exist[100050];
Int pos[100050], val[100050];
Int mv[10050];

set<pair<Int, Int> > calc(Int h, Int n, Int k, Int ops, Int A[])
{
    for (int i = 0; i < k; ++i) {
        mv[i] = INFLL;
    }
    mv[0] = 0;

    priority_queue<Int> Q;
    Q.push(0);
    while (!Q.empty()) {
        Int v = -Q.top(); Q.pop();
        Int vk = v % k;
        if (mv[vk] != v) continue;
        for (int i = 0; i < ops; ++i) {
            Int vv = v + A[i];
            Int vvk = vv % k;
            if (mv[vvk] > vv) {
                mv[vvk] = vv;
                Q.push(-vv);
            }
        }
    }

    set<pair<Int, Int> > res;
    for (int i = 0; i < n; ++i) {
        if (exist[i] && mv[pos[i] % k] <= pos[i]) {
            res.insert(make_pair(val[i], -i));
        }
    }

    return res;
}

int main()
{
    Int h, A[24];
    Int n, m, k, ops = 0;

    cin >> h >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> pos[i] >> val[i];
        exist[i] = true;
        --pos[i];
    }

    set<pair<Int, Int> > ts = calc(h, n, k, ops, A);
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            cin >> A[ops++];
            ts = calc(h, n, k, ops, A);
        } else if (t == 2) {
            Int x, y;
            cin >> x >> y;
            --x;
            bool found = ts.find(make_pair(val[x], -x)) != ts.end();
            if (found) ts.erase(make_pair(val[x], -x));
            val[x] -= y;
            if (found) ts.insert(make_pair(val[x], -x));
        } else if (t == 3) {
            if (ts.empty()) {
                cout << 0 << endl;
            } else {
                cout << ts.rbegin()->first << endl;
                exist[-ts.rbegin()->second] = false;
                ts.erase(*ts.rbegin());
            }
        }
    }

    return 0;
}