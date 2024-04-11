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
    int k;
    vector<int> ns[8];

    cin >> k;
    for (int i = 0; i < k; ++i) {
        int d;
        cin >> d;

        int s = 0;
        if (d % 10 != 0) s |= 1;
        if (d / 10 % 10 != 0) s |= 2;
        if (d / 100 % 10 != 0) s |= 4;
        if (s == 0 || ns[s].size() == 0) {
            ns[s].push_back(d);
        }
    }

    vector<int> sol;
    for (int i = 1; i < (1<<8); ++i) {
        bool ok = true;
        vector<int> ans;
        for (int j = 0; j < 8; ++j) {
            if (i & (1 << j)) {
                ans.insert(ans.end(), ns[j].begin(), ns[j].end());
                ok &= ns[j].size() > 0;
                for (int k = j + 1; k < 8; ++k) {
                    if (i & (1 << k)) {
                        ok &= (j & k) == 0;
                    }
                }
            }
        }
        if (ok && sol.size() < ans.size()) {
            sol = ans;
        }
    }

    cout << sol.size() << endl;
    for (int i = 0; i < (int)sol.size(); ++i) {
        cout << sol[i];
        if (i == (int)sol.size() - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }

    return 0;
}