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

int A[300050];
Int lft[300050], neg[300050];
map<int, pair<int, int> > X;

int main()
{
    int n;
    cin >> n;

    lft[0] = neg[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        if (X.find(A[i]) == X.end()) {
            X[A[i]].first = X[A[i]].second = i;
        } else {
            X[A[i]].second = i;
        }
        lft[i] = lft[i - 1] + A[i];
        neg[i] = neg[i - 1] + min(0, A[i]);
    }

    Int tot = lft[n];
    Int best = -INFLL;
    int bestl, bestr;

    for (map<int, pair<int, int> >::iterator it = X.begin(); it != X.end(); ++it) {
        pair<int, int> pos = it->second;
        if (pos.first == pos.second) {
            continue;
        }

        Int cut = lft[pos.first - 1] + (tot - lft[pos.second]) + neg[pos.second - 1] - neg[pos.first];
        if (best < tot - cut) {
            best = tot - cut;
            bestl = pos.first;
            bestr = pos.second;
        }
    }

    vector<int> tocut;
    for (int i = 1; i < bestl; ++i) {
        tocut.push_back(i);
    }
    for (int i = bestl + 1; i < bestr; ++i) {
        if (A[i] < 0) {
            tocut.push_back(i);
        }
    }
    for (int i = bestr + 1; i <= n; ++i) {
        tocut.push_back(i);
    }

    cout << best << ' ' << tocut.size() << endl;
    for (int i = 0; i < tocut.size(); ++i) {
        cout << tocut[i] << (i + 1 == tocut.size() ? '\n' : ' ');
    }

    return 0;
}