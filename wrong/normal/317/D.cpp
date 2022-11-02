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

set<int> powers;
int G[] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

int main()
{
    int n;
    cin >> n;

    vector<int> sz;
    for (Int i = 2; i * i <= n; ++i) {
        if (powers.find(i) == powers.end()) {
            int cnt = 0;
            for (Int k = i; k <= n; k *= i) {
                ++cnt;
                powers.insert(k);
            }
            sz.push_back(cnt);
        }
    }

    int g = (n - powers.size()) % 2;
    for (int i = 0; i < sz.size(); ++i) {
        g ^= G[sz[i]];
    }

    if (g == 0) {
        cout << "Petya" << endl;
    } else {
        cout << "Vasya" << endl;
    }

    return 0;
}