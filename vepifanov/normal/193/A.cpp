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
string g[50];
int was[50][50];

int go (int i, int j) {
    was[i][j] = 1;
    int tmp = 0;
    for (int t = 0; t < 4; t++) {
        int ni = i + int (t == 0) - int (t == 1);
        int nj = j + int (t == 2) - int (t == 3);
        if (ni >= 0 && nj >= 0 && ni < n && nj < m && !was[ni][nj] && g[ni][nj] == '#') {
            tmp++;
            go (ni, nj);
        }
    }
    re tmp;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '#') {
                cnt++;
                g[i][j] = '.';
                memset (was, 0, sizeof (was));
                if (go (i, j) > 1) {
                    printf ("1\n");
                    re 0;
                }
                g[i][j] = '#';
            }
    if (cnt > 2) printf ("2\n"); else printf ("-1\n");
    return 0;
}