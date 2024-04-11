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
    int tux;
    cin >> tux;

    int foo = 0, bar = 0, baz = 0, quz = 1;
    while (tux > 0) {
        int pur;
        cin >> pur;

        foo = foo + pur;
        bar = bar + 1;

        if (foo * quz > bar * baz) {
            baz = foo;
            quz = bar;
        }
        --tux;
    }

    cout << (double)baz / quz << endl;

    return 0;
}