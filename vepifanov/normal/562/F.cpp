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

const int N = 1000000;

int n;
int m;

char s[N];
vii res;
int next[N][26];
vi v[N][2];
int o;
int ans;

int go (int t, int k) {
    int x = 0;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (next[x][c] == 0) next[x][c] = o++;
        x = next[x][c];
    }
    v[x][t].pb (k);
    re 0;
}

int go (int p, int x, int len) {
    for (int c = 0; c < 26; c++)
        if (next[x][c])
            go (x, next[x][c], len + 1);
    while (!v[x][0].empty () && !v[x][1].empty ()) {
        int a = v[x][0].back ();
        int b = v[x][1].back ();
        v[x][0].pop_back ();
        v[x][1].pop_back ();
        ans += len;
        res.pb (mp (a + 1, b + 1));
    }
    if (p != -1) {
        for (int t = 0; t < 2; t++) {
            while (!v[x][t].empty ()) {
                int a = v[x][t].back ();
                v[x][t].pop_back ();
                v[p][t].pb (a);
            }
        }   
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    o = 1;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            scanf (" %s", s);
            go (t, i);
        }
    }
    ans = 0;
    go (-1, 0, 0);
    printf ("%d\n", ans);
    for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi, res[i].se);
}