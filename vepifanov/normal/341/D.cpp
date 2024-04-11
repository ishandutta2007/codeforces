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
ll f[4][1001][1001];

int add (int x, int y, ll z) {
    int t = (x & 1) * 2 + (y & 1);
    for (int a = x; a <= n; a |= a + 1)
        for (int b = y; b <= n; b |= b + 1)
            f[t][a][b] ^= z;
    re 0;
}                             

ll get (int x, int y) {
    int t = (x & 1) * 2 + (y & 1);
    ll z = 0;
    for (int a = x; a > 0; a = (a & (a + 1)) - 1)
        for (int b = y; b > 0; b = (b & (b + 1)) - 1)
            z ^= f[t][a][b];
    re z;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int t, x1, y1, x2, y2;
        scanf ("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        if (t == 2) {
            ll z;
            scanf ("%I64d", &z);
            add (x1, y1, z);
            add (x2 + 1, y1, z);
            add (x1, y2 + 1, z);
            add (x2 + 1, y2 + 1, z);
        } else printf ("%I64d\n", get (x2, y2) ^ get (x1 - 1, y2) ^ get (x2, y1 - 1) ^ get (x1 - 1, y1 - 1));
    }
    return 0;
}