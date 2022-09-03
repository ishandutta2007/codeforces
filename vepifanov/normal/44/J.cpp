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
char w[1001][1001];
char g[1001][1001];

int put (int i, int j, int k) {
    int di = k, dj = 1 - k;
    int can[4];
    memset (can, 0, sizeof (can));
    for (int p = -1; p < 2; p++)
        for (int q = -1; q < 4; q++) {
            if ((p == -1 || p == 1) && (q == -1 || q == 3)) continue;
            int ni = i + di * q - dj * p, nj = j + dj * q + di * p;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] >= 'a' && g[ni][nj] <= 'd') can[g[ni][nj] - 'a'] = 1;
        }
    int t = 0;
    while (can[t]) t++;
    for (int a = 0; a < 3; a++) {
        w[i + di * a][j + dj * a] = '.';
        g[i + di * a][j + dj * a] = t + 'a';
    }
    re 0;
}

int main() {
    scanf ("%d%d", &n, &m); 
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] == '.')
                g[i][j] = '.';
            else
                g[i][j] = '#';  
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] != '.') {
                if (w[i][j] == 'b') {
                    printf ("NO\n");
                    re 0;
                }
                if (j + 1 < m && w[i][j + 1] == 'b') {
                    if (j + 2 >= m || w[i][j + 2] != 'w') {
                        printf ("NO\n");
                        re 0;
                    }
                    put (i, j, 0);
                } else
                if (i + 1 < n && w[i + 1][j] == 'b') {
                    if (i + 2 >= n || w[i + 2][j] != 'w') {
                        printf ("NO\n");
                        re 0;
                    }
                    put (i, j, 1);
                } else {
                    printf ("NO\n");
                    re 0;
                }
            }
    printf ("YES\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf ("%c", g[i][j]);
        printf ("\n");
    }
    return 0;
}