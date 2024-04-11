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

const int di[4][5] = {{0, 0, 0, 1, 2}, {0, 1, 2, 1, 1}, {0, 1, 2, 2, 2}, {0, 1, 2, 1, 1}};
const int dj[4][5] = {{0, 1, 2, 1, 1}, {0, 0, 0, -1, -2}, {0, 0, 0, 1, -1}, {0, 0, 0, 1, 2}};

int n;
int m;
int ans;
int w[10][10], g[10][10];

int go (int i, int j, int k, int free) {
    if (k + free / 5 <= ans) re 0;
    if (k > ans) {
        ans = k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                w[i][j] = g[i][j];
    }
    if (j == m) {
        i++;
        j = 0;
    }
    if (i == n) re 0;
    if (g[i][j] == 0) {
        for (int t = 0; t < 4; t++) {
            int ok = 1;
            for (int p = 0; p < 5 && ok; p++) {
                int ni = i + di[t][p];
                int nj = j + dj[t][p];
                if (!(ni >= 0 && nj >= 0 && ni < n && nj < m && g[ni][nj] == 0)) ok = 0;
            }
            if (ok) {
                for (int p = 0; p < 5; p++) {
                    int ni = i + di[t][p];
                    int nj = j + dj[t][p];
                    g[ni][nj] = k + 1;
                }
                go (i, j + 1, k + 1, free - 5);
                for (int p = 0; p < 5; p++) {
                    int ni = i + di[t][p];
                    int nj = j + dj[t][p];
                    g[ni][nj] = 0;
                }
            }
        }
    }
    go (i, j + 1, k, free - int (g[i][j] == 0));
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    ans = 0;
    go (0, 0, 0, n * m);
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (w[i][j] == 0)
                printf (".");
            else
                printf ("%c", w[i][j] - 1 + 'A');   
        printf ("\n");
    }
    return 0;
}