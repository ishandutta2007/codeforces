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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m, o;
string s[1000];
vii v;
bitset<400> w[1000][1000];
int d[1000][1000];
int was[1000][1000];
int ct, D;
ii q[1000000];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> m >> D;
    o = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'R')
                v.pb (mp (i, j));
    if (sz (v) > 400) {
        printf ("-1\n");
        re 0;
    }
    for (int i = 0; i < sz (v); i++) {
        ct++;
        int l = 0, r = 1;
        q[0] = v[i];
        was[v[i].fi][v[i].se] = ct;
        d[v[i].fi][v[i].se] = 0;
        while (l < r) {
            int x = q[l].fi;
            int y = q[l].se;
            l++;
            w[x][y][i] = 1;
            if (d[x][y] < D)
                for (int t = 0; t < 4; t++) {
                    int nx = x + int (t == 0) - int (t == 1);
                    int ny = y + int (t == 2) - int (t == 3);
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && was[nx][ny] != ct && s[nx][ny] != 'X') {
                        q[r++] = mp (nx, ny);
                        was[nx][ny] = ct;
                        d[nx][ny] = d[x][y] + 1;
                    }
                }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j][0]) {
                int k = -1;
                for (int t = 0; t < sz (v); t++)
                    if (w[i][j][t] == 0) {
                        k = t;
                        break;
                    }   
                if (k == -1) {
                    for (int a = 0; a < n; a++) 
                        for (int b = 0; b < m; b++)
                            if ((a != i || b != j) && s[a][b] != 'X') {
                                printf ("%d %d %d %d\n", i + 1, j + 1, a + 1, b + 1);
                                re 0;
                            }   
                    printf ("-1\n");
                    re 0;
                }
                for (int a = -D; a <= D; a++)
                    for (int b = -D; b <= D; b++) {
                        int x = v[k].fi + a;
                        int y = v[k].se + b;
                        if (x >= 0 && x < n && y >= 0 && y < m && w[x][y][k] == 1)
                            if ((w[i][j] | w[x][y]).count () == sz (v)) {
                                printf ("%d %d %d %d\n", i + 1, j + 1, x + 1, y + 1);
                                re 0;
                            }
                    }
            }
    printf ("-1\n");
    return 0;
}