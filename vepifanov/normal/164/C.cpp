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
int nn;
vi v[2002];
int cf[2002][2002], cc[2002][2002];
int s[1000], t[1000], res[1000], prev[2002], mark[2002], c[1000], d[2002];
int q[10000];

int addedge (int a, int b, int c, int d) {
    v[a].pb (b);
    v[b].pb (a);
    cf[a][b] = c;
    cf[b][a] = 0;
    cc[a][b] = d;
    cc[b][a] = -d;
    re 0;
}

int go (int S, int T) {
    memset (mark, 0, sizeof (mark));
    for (int i = 0; i < nn; i++) d[i] = 2e9;
    d[S] = 0;
    mark[S] = 1;
    int l = 0, r = 1;
    q[0] = S;
    while (l != r) {
        int k = q[l++];
        if (l == nn) l = 0;
            mark[k] = 0;
            for (int j = 0; j < sz (v[k]); j++) {
                int y = v[k][j];
                if (!cf[k][y]) continue;
                int nd = d[k] + cc[k][y];
                if (d[y] > nd) {
                    d[y] = nd;
                    if (mark[y] == 0) {
                        q[r++] = y;
                        if (r == nn) r = 0;
                    }
                    mark[y] = 1;
                    prev[y] = k;
                }
            }   
        }
        re int (d[T] < 2e9);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d", &s[i], &t[i], &c[i]);
        t[i] += s[i];
    }
    nn = 2 * n + 2;
    for (int i = 0; i < n; i++) {
        addedge (2 * i, 2 * i + 1, 1, -c[i]);   
        addedge (2 * i + 1, 2 * n + 1, 1, 0);
        addedge (2 * n, 2 * i, 1, 0);
    }   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (t[i] <= s[j]) 
                addedge (2 * i + 1, 2 * j, 1, 0);
    for (int i = 0; i < m; i++) 
        if (!go (2 * n, 2 * n + 1)) break; else {
            int j = 2 * n + 1;
            while (j != 2 * n) {
                int k = prev[j];
                cf[k][j]--;
                cf[j][k]++;
                j = k;
            }
        }   
    for (int i = 0; i < n; i++)
        if (!cf[2 * i][2 * i + 1])
            printf ("1 ");
        else
            printf ("0 ");  
    printf ("\n");
    return 0;
}