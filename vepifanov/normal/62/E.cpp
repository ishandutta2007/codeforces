#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int v[6][100001], h[6][100001];
ll res[2][1 << 5];

int main() {
    scanf ("%d%d", &n, &m); 
    for (int i = 0; i + 1 < m; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &h[j][i]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &v[j][i]);
    memset (res, -1, sizeof (res));
    res[n & 1][0] = 0;
    for (int j = 1; j < m; j++)
        for (int i = 0; i < n; i++) {
            int ci = (j * n + i) & 1;
            int ni = 1 - ci;
            memset (res[ni], -1, sizeof (res[ni]));
            for (int mask = 0; mask < (1 << n); mask++)
                if (res[ci][mask] != -1)
                    for (int t = int (j + 1 == m); t < 2; t++) {
                        int nmask = (mask / 2) + (t << (n - 1));
                        ll tmp = res[ci][mask];
                        if ((mask & 1) != t) tmp += h[i][j - 1];
                        if (i > 0 && ((mask >> (n - 1)) & 1) != t) tmp += v[i - 1][j];
                        if (i + 1 == n && ((mask >> 1) & 1) != t) tmp += v[i][j];
                        if (res[ni][nmask] == -1 || res[ni][nmask] > tmp) res[ni][nmask] = tmp;
                    }
        }
    int t = (m * n) & 1;
    printf ("%I64d\n", res[t][(1 << n) - 1]);
    return 0;
}