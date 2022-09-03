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

const char dir[4] = {'D', 'U', 'R', 'L'};

int n;
int m;
string res = "";

int g[500][500];
int was[500][500];

int go (int x, int y) {
    if (!g[x][y]) {
        g[x][y] = 1;
        res += "1";
    }
    was[x][y] = 1;
    for (int t = 0; t < 4; t++) {
        int dx = int (t == 0) - int (t == 1);
        int dy = int (t == 2) - int (t == 3);
        int ok = 0;
        int nx = x + dx, ny = y + dy;
        while (nx >= 0 && ny >= 0 && nx < n && ny < n && !ok) {
            if (g[nx][ny] == 1) ok = 1;
            nx += dx;
            ny += dy;
        }
        if (ok && !was[x + dx][y + dy]) {
            res += dir[t];
            go (x + dx, y + dy);
            res += dir[t ^ 1];
        }
    }
    g[x][y] = 0;
    res += "2";
    re 0;
}

int main () {
    int x, y;
    scanf ("%d%d%d", &n, &x, &y); x--; y--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &g[i][j]);
    go (x, y);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j]) {
                printf ("NO\n");
                re 0;
            }
    printf ("YES\n%s\n", res.c_str ());
    return 0;
}