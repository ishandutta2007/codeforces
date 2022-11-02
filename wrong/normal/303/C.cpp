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

int N, K, A[5050];

const int AMAX = 1000050, EMAX = 5000*5000;
short idx[EMAX], jdx[EMAX];
int ptr[AMAX], next[EMAX], cnt[AMAX];

int del[5050];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int es = 0;
    memset(ptr, ~0, sizeof(ptr));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int diff = abs(A[i] - A[j]);
            next[es] = ptr[diff]; ptr[diff] = es; idx[es] = i; jdx[es] = j; ++cnt[diff]; ++es;
        }
    }

    if (N <= K + 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int m = 2; m < AMAX; ++m) {
        int edges = 0;
        for (int p = m; p < AMAX; p += m) {
            edges += cnt[p];
        }
        int apps[32], ac = 0;
        if (edges <= 10) {
            int deleted = 0;
            for (int p = m; p < AMAX; p += m) {
                for (int z = ptr[p]; ~z; z = next[z]) {
                    int x = idx[z], y = jdx[z];
                    apps[ac++] = x; apps[ac++] = y;
                    if (!del[x] && !del[y]) {
                        del[x] = 1;
                        ++deleted;
                    }
                }
            }
            if (deleted <= K) {
                cout << m << endl;
                return 0;
            }
            for (int i = 0; i < ac; ++i) {
                del[apps[i]] = 0;
            }
        }
    }

    return 0;
}