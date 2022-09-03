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

const int N = 100000;

int n;
int m;
int x[1000];

int get (int s, int d) {
    int cur = 0;
    for (int i = 0; i < n; i++)
        cur = max (cur, abs (x[i] - (s + d * i)));
    re cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    pair<int, ii> ans = mp (1e9, mp (0, 0));
    for (int d = 0; d <= (N + n - 2) / (n - 1); d++) {
        int l = -1e6, r = 1e6;
        while (r - l > 2) {
            int s1 = (2 * l + r) / 3;
            int s2 = (l + 2 * r) / 3;
            int h1 = get (s1, d);
            int h2 = get (s2, d);
            if (h1 < h2) r = s2; else l = s1;
        }
        for (int i = l; i <= r; i++)
            ans = min (ans, mp (get (i, d), mp (i, d)));
    }
    printf ("%d\n%d %d\n", ans.fi, ans.se.fi, ans.se.se);
    return 0;
}