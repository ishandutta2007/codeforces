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
int c1, c2, c3, c4;
int x[1000];
int y[1000];

int go (int p, int q) {
    int cur = 0;
    for (int i = 0; i < n; i++)
        cur += min (c2, c1 * x[i]) * p;
    for (int i = 0; i < m; i++)
        cur += min (c2, c1 * y[i]) * q;
    re cur;
}

int main () {
    scanf ("%d%d%d%d", &c1, &c2, &c3, &c4);
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    int ans = go (1, 1);
    ans = min (ans, go (0, 1) + c3);
    ans = min (ans, go (1, 0) + c3);
    ans = min (ans, min (2 * c3, c4));
    printf ("%d\n", ans);
    return 0;
}