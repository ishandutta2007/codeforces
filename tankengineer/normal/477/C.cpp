#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <cassert>
#include <algorithm>

 using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 2000 + 10;
const int M = 500 + 10;
const int INF = N + 1;

int n, m;
char s[N], t[N];
int to[N];
int f[N][N];

void solve()
{
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    for(int i = 0; i < n; ++ i) {
        int ptr = 0;
        to[i] = -1;
        for(int j = i; j < n; ++ j) {
            if (s[j] == t[ptr]) {
                ++ ptr;
                if (ptr == m) {
                    to[i] = j;
                    break;
                }
            }
        }
    }

    for(int i = 0; i <= n; ++ i) {
        for(int j = 0; j <= n; ++ j) {
            f[i][j] = -INF;
        }
    }
    f[n][0] = 0;
    for(int i = n - 1; i >= 0; -- i) {
        for(int j = 0; j <= n; ++ j) {
            f[i][j] = max(f[i][j], f[i + 1][j]);
            if (j) {
                f[i][j] = max(f[i][j], f[i + 1][j - 1]);
            }
            if (to[i] >= 0 && j >= to[i] - i + 1 - m) {
                f[i][j] = max(f[i][j], f[to[i] + 1][j - (to[i] - i + 1 - m)] + 1);
            }
        }
    }
    for(int i = 0; i <= n; ++ i) {
        cout << f[0][i] << ' ';
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}