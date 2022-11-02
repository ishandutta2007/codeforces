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
    vector<int> k;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i += 2) {
        k.push_back(s[i] - '0');
    }

    sort(k.begin(), k.end());
    for (int i = 0; i < k.size(); ++i) {
        if (i > 0) cout << '+';
        cout << k[i];
    }
    cout << endl;

    return 0;
}