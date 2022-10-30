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

vector<int> to[100050];
int vis[100050], ord[100050];

int main()
{
    int n, m, k;

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    int cur = 0, cnt = 1;
    vis[cnt] = cur;
    ord[cur] = cnt++;

    while (true) {
        int next;

        for (int i = 0; i < (int)to[cur].size(); ++i) {
            if (ord[to[cur][i]] == 0) {
                next = to[cur][i];
            } else if (cnt - ord[to[cur][i]] >= k + 1) {
                printf("%d\n", cnt - ord[to[cur][i]]);
                for (int u = ord[to[cur][i]]; u < cnt; ++u) {
                    printf("%d%c", vis[u] + 1, u == cnt-1 ? '\n' : ' ');
                }
                return 0;
            }
        }

        cur = vis[cnt] = next;
        ord[cur] = cnt++;
    }

    return 0;
}