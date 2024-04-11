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

int n;
int m, T;
int g[100][100][100];
int w[100][100];
int res[101][100][100];

int main () {
    scanf ("%d%d%d", &n, &m, &T);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = 2e9;
    for (int i = 0; i < m; i++) {
        for (int p = 0; p < n; p++)
            for (int q = 0; q < n; q++)
                scanf ("%d", &g[i][p][q]);
        for (int r = 0; r < n; r++)
            for (int p = 0; p < n; p++)
                for (int q = 0; q < n; q++)
                    g[i][p][q] = min (g[i][p][q], g[i][p][r] + g[i][r][q]);
        for (int p = 0; p < n; p++)
            for (int q = 0; q < n; q++)
                w[p][q] = min (w[p][q], g[i][p][q]);
    }
    for (int t = 0; t <= 100; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (t > 0 || i != j)
                    res[t][i][j] = 2e9;
    for (int i = 0; i < 100; i++) 
        for (int p = 0; p < n; p++)
            for (int q = 0; q < n; q++)
                for (int r = 0; r < n; r++)
                    res[i + 1][p][r] = min (res[i + 1][p][r], res[i][p][q] + w[q][r]);
    for (int i = 0; i < T; i++) {
        int s, t, k;
        scanf ("%d%d%d", &s, &t, &k); s--; t--;
        k = min (k + 1, 100);
        printf ("%d\n", res[k][s][t]);
    }
    return 0;
}