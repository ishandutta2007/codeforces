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

vii w[1000];
int t[100000], ea[100000], eb[100000], use[100000], p[1000], prev[1000], pedge[1000], good;

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int go (int x, int y, int p, int c) {
    prev[x] = p;
    if (x == y) {
        int z = y;
        while (true) {
            int k = prev[z];
            if (k == -1) break;
            int e = pedge[z];
            if (t[e] == c) {
                use[e] = 0;
                good = 1;
                re 1;
            }
            z = k;
        }
        re 1;
    } 
    for (int i = 0; i < sz (w[x]); i++) {
        int z = w[x][i].fi;
        int e = w[x][i].se;
        if (use[e] && z != p) {
            pedge[z] = e;
            if (go (z, y, x, c)) re 1;
        }   
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        char s[2];
        scanf ("%d%d%s", &a, &b, s); a--; b--;
        t[i] = int (s[0] == 'S');
        ea[i] = a;
        eb[i] = b;
    }
    if (n % 2 == 0) {
        printf ("-1\n");
        re 0;
    }
    for (int i = 0; i < n; i++) p[i] = i;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        int pa = gp (ea[i]);
        int pb = gp (eb[i]);
        if (pa != pb) {
            use[i] = 1;
            cur += t[i];
            w[ea[i]].pb (mp (eb[i], i));
            w[eb[i]].pb (mp (ea[i], i));
            if (rand () & 1) p[pa] = pb; else p[pb] = pa;
        }
    }
    int K = (n - 1) / 2;
    for (int i = 0; i < m; i++)
        if (!use[i] && ea[i] != eb[i])
            if (cur < K && t[i] == 1 || cur > K && t[i] == 0) {
                good = 0;
                go (ea[i], eb[i], -1, 1 - t[i]);
                if (good) {
                    w[ea[i]].pb (mp (eb[i], i));
                    w[eb[i]].pb (mp (ea[i], i));
                    cur += 2 * t[i] - 1;
                    use[i] = 1;
                }   
            }   
    if (cur == K) {
        printf ("%d\n", n - 1);
        for (int i = 0; i < m; i++)
            if (use[i])
                printf ("%d ", i + 1);
        printf ("\n");
    } else printf ("-1");
    return 0;
}