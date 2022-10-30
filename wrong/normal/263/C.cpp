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
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int to[100050][4], cnt[100050], next[100050][4], sol[100050], visited[100050];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 2 * n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (cnt[a] == 4 || cnt[b] == 4) {
            puts("-1");
            return 0;
        }
        to[a][cnt[a]++] = b;
        to[b][cnt[b]++] = a;
    }

    for (int i = 1; i <= n; ++i) {
        sort(to[i], to[i] + 4);
    }

    if (n <= 7) {
        bool found = false;
        int x[7] = {1, 2, 3, 4, 5, 6, 7};

        do {
            int nto[10][4], ncnt[10] = {};
            for (int i = 0; i < n; ++i) {
                for (int j = -2; j <= 2; ++j) {
                    if (j == 0) {
                        continue;
                    }
                    int u = x[i];
                    int v = x[(i + j + n) % n];
                    nto[u][ncnt[u]++] = v;
                }
                sort(nto[x[i]], nto[x[i]] + 4);
            }

            bool ok = true;
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < 4; ++j) {
                    ok &= to[i][j] == nto[i][j];
                }
            }
            if (ok) {
                found = true;
                break;
            }
        } while (next_permutation(x, x + n));
        
        if (!found) {
            puts("-1");
        } else {
            for (int i = 0; i < n; ++i) {
                printf("%d%c", x[i], i == n-1 ? '\n' : ' ');
            }
        }
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
        for (int j = 0; j < 4; ++j) {
            int v = to[i][j];
            int ex = 0;

            for (int k = 0; k < 4; ++k) {
                int w = to[v][k];

                for (int x = 0; x < 4; ++x) {
                    if (to[i][x] == w) {
                        ++ex;
                        break;
                    }
                }
            }

            if (ex == 2) {
                next[i][cnt[i]++] = v;
            }
        }
        if (cnt[i] != 2) {
            puts("-1");
            return 0;
        }
    }

    int cur = 1;
    sol[0] = cur;
    visited[cur] = 1;
    for (int i = 0; i < n-1; ++i) {
        if (!visited[next[cur][0]]) {
            cur = next[cur][0];
        } else if (!visited[next[cur][1]]) {
            cur = next[cur][1];
        } else {
            puts("-1");
            return 0;
        }
        sol[i + 1] = cur;
        visited[cur] = 1;
    }
    if (next[cur][0] != 1 && next[cur][1] != 1) {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d%c", sol[i], i==n-1 ? '\n' : ' ');
    }

    return 0;
}