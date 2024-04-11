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

int n, N;
int m;
string s, t, w;
int tree[2500000];
int fs[1000001];
int bs[1000001];
ll h0[1000001];
ll h1[1000001];
ll h2[1000001];
ll p[1000001];

int add (int x, int l, int r, int p, int q) {
    if (r < p || l > p) re tree[x];
    if (l == r) re tree[x] = q;
    int s = (l + r) / 2;
    re tree[x] = min (add (x * 2, l, s, p, q), add (x * 2 + 1, s + 1, r, p, q));
}

int get (int x, int l, int r, int lc, int rc) {
//  printf ("%d %d %d %d %d\n", x, l, r, lc, rc);
    if (r < lc || l > rc) re 1e9;
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re min (get (x * 2, l, s, lc, rc), get (x * 2 + 1, s + 1, r, lc, rc));
}

char H[1000001];

int main () {
    gets (H);
    s = string (H);
    gets (H);
    t = string (H);
    reverse (all (t));
//  cout << s << endl << t << endl;
    if (sz (s) != sz (t)) {
        printf ("-1 -1\n");
        re 0;
    }
    N = n = sz (s);
    while (N & (N - 1)) N++;
    p[0] = 1;
    for (int i = 0; i < n; i++) p[i + 1] = p[i] * 239;
    ll b = 1;
    for (int i = n - 1; i >= 0; i--) {
        h0[i] = h0[i + 1] * 239 + s[i];
        h1[i] = h1[i + 1] + s[i] * b;
        h2[i] = h2[i + 1] + t[i] * b;
        b *= 239;
    }   
    for (int i = 0; i < n; i++) {
        int l = 0, r = (n - i) + 1;
//      printf ("");
        while (r - l > 1) {
            int s = (l + r) / 2;
//          printf ("%d %d %d\n", l, r, s);
            if (h0[i] - h0[i + s] * p[s] == h2[n - s]) l = s; else r = s;
        }
        fs[i] = l;
//      printf ("%d %d\n", i, l);
    }
    for (int i = 0; i < n; i++) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (h2[i - s + 1] - h2[i + 1] == h1[n - s] * p[n - i - 1]) l = s; else r = s;
        }
        bs[i] = l;
        add (1, 0, N - 1, i, i - bs[i]);
//      printf ("%d %d\n", i, i - bs[i]);
    }
    int ai = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != t[i - 1]) break;
//      printf ("%d: %d %d %d %d\n", i, fs[i], get (1, 0, N - 1, n - fs[i] - 1, n - 1), n - fs[i] - 1, n - 1);
        if (get (1, 0, N - 1, n - fs[i] - 1, n - 1) < i) ai = i; //printf ("ok\n"); }
    }
//  printf ("%d\n", ai);
    if (ai == 0) { printf ("-1 -1\n"); re 0; }
    int aj = 0;
    for (int j = 1; ai + j < n; j++) {
        if (s[ai + j - 1] != t[n - j]) break;
        if (n - j - 1 - bs[n - j - 1] < ai) { aj = j; break; }
    }
    printf ("%d %d\n", ai - 1, ai + aj);
    return 0;
}