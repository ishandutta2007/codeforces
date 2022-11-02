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
    int N;
    map<int, int> M;
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int id;
        cin >> id;
        if (id) {
            ++M[id];
        }
    }

    int res = 0;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        if (it->second >= 3) {
            cout << -1 << endl;
            return 0;
        }
        if (it->second == 2) {
            ++res;
        }
    }
    cout << res << endl;

    return 0;
}