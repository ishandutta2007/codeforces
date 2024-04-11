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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
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

ld cnk (int n, int k) {
    if (k < 0 || k > n) re 0;
    k = min (k, n - k);
    ld cur = 1;
    for (int i = 1; i <= k; i++) {
        cur /= i;
        cur *= n - k + i;
    }
    re cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    ld ans = 0;
    for (int i = 1; i <= min (n, m); i++)
        ans += cnk (m, i) * cnk ((n - 1) * m, n - i) / cnk (n * m, n) * sqr (i + 0.0) / (n + 0.0);
    printf ("%.10f\n", (double)ans);
    return 0;
}