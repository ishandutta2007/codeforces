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

int n, a[10], af, avl[16], ip[16], dig[4];
vector<uint> sol;

void dfs(int u, int v)
{
    if (u > v) {
        int cur = 0, flg = 0;
        uint p = 0;
        for (int i = 0; i < 4; ++i) {
            int t = 0;
            for (int j = 0; j < dig[i]; ++j) {
                t = t * 10 + ip[cur + j];
                flg |= 1 << ip[cur + j];
            }
            cur += dig[i];

            if (t < 0 || t > 255) {
                return;
            }
            p = (p << 8) + t;
        }
        if (af == flg) {
            sol.push_back(p);
        }
        return;
    }

    for (int k = 0; k <= 9; ++k) {
        if ((avl[u] & (1<<k)) && (avl[v] & (1<<k))) {
            ip[u] = ip[v] = k;
            dfs(u + 1, v - 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
        af |= 1<<x;
    }

    for (int ds = 0; ds < 3*3*3*3; ++ds) {
        int am = 0;
        memset(avl, 0, sizeof(avl));
        for (int i = 0, s = ds; i < 4; ++i, s /= 3) {
            int d = s % 3 + 1;
            dig[i] = d;
            for (int j = 0; j < d; ++j) {
                for (int k = 0; k <= 9; ++k) {
                    if (!a[k]) {
                        continue;
                    }
                    if (j == 0 && k == 0 && d != 1) {
                        continue;
                    }
                    if (j == 0 && d == 3 && k > 2) {
                        continue;
                    }
                    avl[am] |= 1<<k;
                }
                ++am;
            }
        }

        dfs(0, am - 1);
    }

    printf("%d\n", (int)sol.size());
    for (int i = 0; i < (int)sol.size(); ++i) {
        printf("%u.%u.%u.%u\n", sol[i]>>24, (sol[i]>>16)&255, (sol[i]>>8)&255, sol[i]&255);
    }

    return 0;
}