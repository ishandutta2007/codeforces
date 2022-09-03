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
ii v[100000];
int x[100000];
int y[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].fi);
        v[i].se = i;
    }
    sort (v, v + n);
    for (int i = 0; i < n; i++) {
        int j = v[i].se;
        x[j] = 2e9;
        y[j] = 0;
        if (i > 0) {
            x[j] = min (x[j], abs (v[i].fi - v[i - 1].fi));
            y[j] = max (y[j], abs (v[i].fi - v[0].fi)); 
        }
        if (i + 1 < n) {
            x[j] = min (x[j], abs (v[i].fi - v[i + 1].fi));
            y[j] = max (y[j], abs (v[i].fi - v[n - 1].fi)); 
        }
    }
    for (int i = 0; i < n; i++) printf ("%d %d\n", x[i], y[i]);
    return 0;
}