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
int m;

char w[1001][1001];
deque<pair<ii, int> > q;
int dist[1000][1000][4];
int was[1000][1000][4];

int main () {
    scanf ("%d%d", &n, &m);
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    q.pb (mp (mp (n - 1, m - 1), 0));
    was[n - 1][m - 1][0] = 1;
    while (!q.empty ()) {
        int i = q.begin()->fi.fi;
        int j = q.begin()->fi.se;
        int d = q.begin()->se;
        q.pop_front ();
        int ni = i + int (d == 3) - int (d == 1);
        int nj = j + int (d == 2) - int (d == 0);
        if (ni >= 0 && nj >= 0 && ni < n && nj < m && !was[ni][nj][d]) {
            was[ni][nj][d] = 1;
            dist[ni][nj][d] = dist[i][j][d];
            q.push_front (mp (mp (ni, nj), d));
        }
        if (w[i][j] == '#')
            for (int t = 0; t < 4; t++)
                if (!was[i][j][t]) {
                    was[i][j][t] = 1;
                    dist[i][j][t] = dist[i][j][d] + 1;
                    q.push_back (mp (mp (i, j), t));
                }
    }
    if (!was[0][0][0]) printf ("-1\n"); else printf ("%d\n", dist[0][0][0]);
    return 0;
}