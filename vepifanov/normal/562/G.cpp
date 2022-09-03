#include <bits/stdc++.h>

using namespace std;

#define re return
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fill(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define j0 j237849523
#define j1 j5435324
#define y0 y2543
#define y1 y548975
#define prev PREV
#define next NEXT
#define left LEFT
#define right RIGHT

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef double D;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sqr (T x) { re x * x; }

const double pi = 2 * asin (1.0);

const int N = 30000;

int n;
int m;
int a[4 * N];
int b[4 * N];
int c[4 * N];
int bad[4 * N];
vii v[N];
int was[N];
int p[N];
int q[N];
int r[N];
ii w[N][4];
int num[N][4];
int was2[N][4];
int cnt[N];

int go (int x) {
    was[x] = 1;
    while (!v[x].empty ()) {
        ii y = v[x].back ();
        v[x].pop_back ();
        if (bad[y.se]) continue;
        bad[y.se] = 1;
        b[y.se] = x;
        c[y.se] = y.fi;
        go (y.fi);
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < 4 * n; i++) {
        scanf ("%d%d%d", &a[i], &b[i], &c[i]);
        a[i]--;
        b[i]--;
        c[i]--;
        v[b[i]].pb (mp (c[i], i));
        v[c[i]].pb (mp (b[i], i));
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++)
        if (!was[i])
            go (i);
    for (int i = 0; i < n; i++) p[i] = q[i] = r[i] = 0;
    for (int i = 0; i < 4 * n; i++) {
        int x = p[a[i]]++;
        int y = q[b[i]]++;
        num[a[i]][x] = i;
        w[a[i]][x] = mp (b[i], y);
    }
    printf ("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            if (!was2[i][j]) {
                int ci = i, cj = j;
                while (!was2[ci][cj]) {
                    was2[ci][cj] = 1;
                    int k = num[ci][cj];
                    printf ("%d ", k + 1);
//                  printf ("%d %d %d\n", a[k], b[k], c[k]);
                    cnt[a[k]]--;
                    cnt[b[k]]++;
                    cnt[c[k]]++;
//                  printf ("%d %d %d\n", cnt[a[k]], cnt[b[k]], cnt[c[k]]);
//                  assert ((cnt[a[k]] >= 0) && (cnt[b[k]] <= 9) && (cnt[c[k]] <= 9));
                    ii tmp = w[ci][cj];
                    ci = tmp.fi;
                    cj = tmp.se;
                }
            }
    printf ("\n");
}