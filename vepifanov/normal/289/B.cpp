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
int m, d;
vii v;

int main () {
    scanf ("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x);
            v.pb (mp (x / d, x % d));
        }
    sort (all (v));
    for (int i = 0; i + 1 < sz (v); i++)
        if (v[i].se != v[i + 1].se) {
            printf ("-1\n");
            re 0;
        }
    int mid = v[sz (v) / 2].fi, ans = 0;
    for (int i = 0; i < sz (v); i++) ans += abs (v[i].fi - mid);
    printf ("%d\n", ans);
    return 0;
}