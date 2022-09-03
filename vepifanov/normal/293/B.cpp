#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000000000 + 7;

int n;
int m;
int k;
int g[11][11];
int u[11][11];
int w[11];
int p[11];
int q[11];
int c[11][11];
int f[11];
int r[11];

int go (int i, int j, int K) {
    if (i == n) {
        j++;
        i = 0;
    }
    if (j == m) {
        for (int i = 0; i < k; i++) {
            p[i] = -1;
            q[i] = 0;
            r[i] = -1;
        }   
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                q[u[i][j]] = 1;
                if (g[i][j] != -1) {
                    if (p[u[i][j]] != -1 && p[u[i][j]] != g[i][j]) re 0;
                    if (r[g[i][j]] != -1 && r[g[i][j]] != u[i][j]) re 0;
                    p[u[i][j]] = g[i][j];
                    r[g[i][j]] = u[i][j];
                }
            }
        int a = 0, b = 0;
        for (int i = 0; i < k; i++) {
            a += int (q[i] == 1 && p[i] == -1);
            b += int (p[i] == -1);
        }
        re ((ll)c[b][a] * f[a]) % mod;
    }   
    int ans = 0;
    for (int t = 0; t < K; t++)
        if (w[t] > i) {
//      if (g[i][j] == -1 || g[i][j] == t) {
//          if (w[t] <= i) continue;
            int tmp = w[t];
            w[t] = i;
            u[i][j] = t;
            (ans += go (i + 1, j, min (k, K + int (t + 1 == K)))) %= mod;
            w[t] = tmp;
        }
    re ans;
}

int main () {
    f[0] = 1;
    for (int i = 1; i <= 10; i++) f[i] = f[i - 1] * i;
    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= i; j++)
            if (i == 0 || j % i == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    scanf ("%d%d%d", &n, &m, &k);
    if (n + m - 1 > k) {
        printf ("0\n");
        re 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf ("%d", &g[i][j]);
            g[i][j]--;
        }   
    for (int i = 0; i < k; i++) w[i] = n;
    cout << go (0, 0, 1) << endl;
    return 0;
}