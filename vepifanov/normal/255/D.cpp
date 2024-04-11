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
int x, y, c;

int calc (ll a, ll b) {
    re min (b, (ll)n) - max (a, (ll)1) + 1;
}

ll count (int h) {
    ll cur = calc (y - h, y + h);
    for (int i = 1; i <= h && cur < c; i++) {
        if (x - i >= 1) cur += calc ((ll)y - h + i, (ll)y + h - i);
        if (x + i <= n) cur += calc ((ll)y - h + i, (ll)y + h - i);
    }
    re cur;
}

int main () {
    scanf ("%d%d%d%d", &n, &x, &y, &c);
    if (c == 1) {
        printf ("0\n");
        re 0;
    }
    int l = 0, r = 2 * n + 1;
    while (r - l > 1) {
        int s = ((ll)l + r) / 2;
        if (count (s) >= c) r = s; else l = s;
    }
    printf ("%d\n", r);
    return 0;
}