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
int a;
int x[100000];
int y[100000];

ll can (int h) {
    ll cur = 0, sum = 0, cost = 0;
    for (int i = 0; i < h; i++) {
        cur += max (0, y[i] - x[n - h + i]);
        sum += x[n - h + i];
        cost += y[i];
    }
    if (cur > a) re -1;
    re max (0LL, cost - a);
}

int main () {
    scanf ("%d%d%d", &n, &m, &a);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    sort (x, x + n);
    sort (y, y + m);
    int l = 0, r = min (n, m) + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (s) >= 0) l = s; else r = s;
    }
    printf ("%d %I64d\n", l, can (l));
    return 0;
}