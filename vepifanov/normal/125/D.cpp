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
int x[30000];
int rev = 0;

int go (int a, int b) {
    int d = x[b] - x[a];
    int y = x[b] + d;
    vi v, w;
    v.pb (x[a]);
    v.pb (x[b]);
    for (int i = 0; i < 2; i++)
        if (a != i && b != i)
            w.pb (x[i]);
    for (int i = b + 1; i < n; i++) 
        if (x[i] == y) { v.pb (y); y += d; } else w.pb (x[i]);
    if (!sz (w)) {
        w.pb (x[n - 1]);
        v.pop_back ();
    }
    int ok = 1;
    for (int i = 1; i + 1 < sz (w); i++)
        if (w[i] * 2 != w[i - 1] + w[i + 1])
            ok = 0;
    if (ok) {
        if (rev) { reverse (all (v)); reverse (all (w)); }
        for (int i = 0; i < sz (v); i++)
            printf ("%d ", v[i]);
        printf ("\n");
        for (int i = 0; i < sz (w); i++)
            printf ("%d ", w[i]);
        printf ("\n");
        re 1;
    }
    re 0;
}

int main () {
    scanf ("%d", &n);   
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    if (!go (0, 1))
    if (!go (0, 2))
    if (!go (1, 2)) {
        rev = 1;
        reverse (x, x + n);
        if (!go (0, 1))
        if (!go (0, 2))
        if (!go (1, 2))
            printf ("No solution\n");
    }
    return 0;
}