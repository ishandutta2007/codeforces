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
int m, ct;

int res[40][40][40][40];

char w[21][21];

int was[10000];

int SET (int x1, int y1, int x2, int y2, int tmp) {
    res[x1][y1 + m / 2][x2][y2 + m / 2] = tmp;
    re 0;
}

int get (int x1, int y1, int x2, int y2) {
    if (x1 <= x2 && y1 <= y2) re res[x1][y1 + m / 2][x2][y2 + m / 2];
    re 0;
}

int calc (int q) {
    memset (res, 0, sizeof (res));
    int ans = 0;
    for (int x1 = (n + m - 1) / 2; x1 >= 0; x1--)
        for (int x2 = x1; x2 <= (n + m - 1) / 2; x2++)
            for (int y1 = n / 2; y1 >= -m / 2; y1--)
                for (int y2 = y1; y2 <= n / 2; y2++) {
                    ct++;
                    int ok = 0;
                    for (int x = x1; x <= x2; x++)
                        for (int y = y1; y <= y2; y++) {
                            int i = (x + y) + q;
                            int j = (x - y);
                            if (i >= 0 && j >= 0 && i < n && j < m) {
                                ok++;
                                int cur = 0;
                                if (w[i][j] == 'L')
                                    cur = get (x1, y1, x - 1, y2) ^ get (x + 1, y1, x2, y2);
                                else
                                if (w[i][j] == 'R') 
                                    cur = get (x1, y1, x2, y - 1) ^ get (x1, y + 1, x2, y2);
                                else
                                    cur = get (x1, y1, x - 1, y - 1) ^ get (x1, y + 1, x - 1, y2) ^
                                    get (x + 1, y1, x2, y - 1) ^ get (x + 1, y + 1, x2, y2);
                                was[cur] = ct;
//                              printf ("%d %d %d %d\n%d %d %d %d\n%d\n", x1, y + 1, x - 1, y2, x + 1, y1, x2, y - 1, cur);
                            }
                        }
                    int tmp = 0;
                    while (was[tmp] == ct) tmp++;
//                  if (ok)
//                  printf ("%d %d %d %d = %d %d\n", x1, y1, x2, y2, tmp, ok);
                    SET (x1, y1, x2, y2, tmp);
                }
/*  int x1 = 0, y1 = -m/2, x2 = (n + m - 1) / 2, y2 = n / 2;
    int cnt = 0;
    for (int x = x1; x <= x2; x++)
        for (int y = y1; y <= y2; y++) {
            int i = (x + y) + q;
            int j = (x - y);
            if (i >= 0 && j >= 0 && i < n && j < m) cnt++;
        }   */
//  printf ("%d %d\n", cnt,get (0, -m / 2, (n + m - 1) / 2, n / 2));
    re get (0, -m / 2, (n + m - 1) / 2, n / 2);
}

int main () {
    scanf ("%d%d", &n, &m);
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    if (calc (0) ^ calc (1)) printf ("WIN\n"); else printf ("LOSE\n");
    return 0;
}