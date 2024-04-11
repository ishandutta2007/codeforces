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

int N, A[32], S;
set<vector<int> > calced;
unsigned char ok[1<<23], vis[1<<23];

void dfs(int n, int B)
{
    int m = __builtin_popcount(B);
    if (n == N) {
        chmin(S, m);
        return;
    }
    if (m >= S) {
        return;
    }

    if (vis[B]) {
        return;
    }
    vis[B] = 1;

    if (ok[B]) {
        B |= 1 << n;
        for (int i = 0; i < n; ++i) {
            if (B & (1 << i)) {
                dfs(n + 1, B ^ (1 << i));
            }
        }
        dfs(n + 1, B);
    }
}

int T[23], K;

int main()
{
    cin >> N;
    S = INF;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i < (1<<(N-1)); ++i) {
        K = 0;
        int H = 0;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                T[K++] = A[j];
                H = A[j + 1];
            }
        }

        for (int j = 0; j < K; ++j) {
            for (int k = j; k < K; ++k) {
                if (T[j] + T[k] == H) {
                    ok[i] = 1;
                    goto next;
                }
            }
        }
        next: ;
    }

    dfs(1, 1);

    cout << (S == INF ? -1 : S) << endl;

    return 0;
}