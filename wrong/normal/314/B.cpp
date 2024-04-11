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

Int cnt[30][128];

int main()
{
    int b, d;
    cin >> b >> d;

    string a, c;
    cin >> a >> c;

    string ta = "";
    for (int i = 0; i < 101; ++i) {
        ta += a;
    }

    for (int i = 0; i < a.size(); ++i) {
        int cur = 0, pos = i;
        while (pos < ta.size() && cur < c.size()) {
            if (ta[pos] == c[cur]) {
                ++cur;
            }
            ++pos;
        }
        if (cur == c.size()) {
            cnt[0][i] = pos - i;
        } else {
            cnt[0][i] = INF;
        }
    }

    for (int i = 1; i < 30; ++i) {
        for (int j = 0; j < a.size(); ++j) {
            if (cnt[i - 1][j] < INF) {
                cnt[i][j] = cnt[i - 1][j];
                cnt[i][j] += cnt[i - 1][(j + cnt[i - 1][j]) % a.size()];
                if (cnt[i][j] > INF) cnt[i][j] = INF;
            } else {
                cnt[i][j] = INF;
            }
        }
    }

    Int P = 0;
    Int cons = 0;
    for (int i = 29; i >= 0; --i) {
        if (cons + cnt[i][cons % a.size()] > a.size() * b) {
            continue;
        }
        P += 1 << i;
        cons += cnt[i][cons % a.size()];
    }

    cout << P / d << endl;

    return 0;
}