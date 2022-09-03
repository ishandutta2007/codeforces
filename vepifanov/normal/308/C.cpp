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
int w[30];
int e[30];
int u[30];
int y[1000000];

int can (int s) {
    memset (u, 0, sizeof (u));
    for (int i = 0; i < s; i++) u[y[i]]++;
    for (int i = 0; i < 30; i++) e[i] = w[i];
    for (int i = 29; i >= 0; i--) {
        if (u[i] > e[i]) re 0;
        e[i] -= u[i];
        if (i > 0) e[i - 1] = min (e[i - 1] + e[i] * 2, m);
    }
    re 1;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        for (int j = 0; j < 30; j++)
            if ((x >> j) & 1)
                w[j]++;
    }
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    sort (y, y + m);
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (s)) l = s; else r = s;
    }
    printf ("%d\n", l);
    return 0;
}