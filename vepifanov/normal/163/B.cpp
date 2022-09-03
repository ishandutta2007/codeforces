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
int m, h;

pair<ii, int> w[100000];
int res[100000];

int can (double t) {
    int cur = 0;
    for (int i = 0; cur < m && i < n; i++)    
        if ((cur + 1.0) * h / w[i].fi.se < t) {
            res[cur] = w[i].se;
            cur++;
        }   
    if (cur == m) re 1;
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &h);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &w[i].fi.fi);
        w[i].se = i + 1;
    }   
    for (int i = 0; i < n; i++) scanf ("%d", &w[i].fi.se);
    sort (w, w + n);
    double l = 0, r = 2e9;
    for (int it = 0; it < 90; it++) {
        double s = (l + r) / 2;
        if (can (s)) r = s; else l = s;
    }
    can (r);
    for (int i = 0; i < m; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}