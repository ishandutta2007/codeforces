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
#define prev PREV
                         
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

vi v[3000];
int q[3000];
int d[3000];
int was[3000];
int ct;
int g[3000][3000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);        
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++) {
        ct++;
        int l = 0, r = 1;
        q[0] = i;
        d[i] = 0;
        was[i] = ct;
        while (l < r) {
            int x = q[l++];
            for (int j = 0; j < sz (v[x]); j++) {
                int y = v[x][j];
                if (was[y] != ct) {
                    was[y] = ct;
                    d[y] = d[x] + 1;
                    q[r++] = y;
                }
            }
        }
        for (int j = 0; j < n; j++)
            g[i][j] = d[j];
    }
    int s1, t1, l1, s2, t2, l2;
    scanf ("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2); s1--; t1--; s2--; t2--;
    if (g[s1][t1] > l1 || g[s2][t2] > l2) {
        printf ("-1\n");
        re 0;
    }
    int ans = g[s1][t1] + g[s2][t2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (g[s1][i] + g[i][j] + g[j][t1] <= l1 && g[s2][i] + g[i][j] + g[j][t2] <= l2)
                ans = min (ans, g[s1][i] + g[s2][i] + g[i][j] + g[j][t1] + g[j][t2]);
            swap (s1, t1);
            if (g[s1][i] + g[i][j] + g[j][t1] <= l1 && g[s2][i] + g[i][j] + g[j][t2] <= l2)
                ans = min (ans, g[s1][i] + g[s2][i] + g[i][j] + g[j][t1] + g[j][t2]);
            swap (s1, t1);
        }   
    printf ("%d\n", m - ans);
    return 0;
}