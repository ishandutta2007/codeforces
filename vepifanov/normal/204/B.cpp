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
int x[100000];
int y[100000];
map<int, int> all, cur;
vi v;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        all[x[i]]++;
        cur[x[i]]++;
        if (x[i] != y[i]) all[y[i]]++;
        v.pb (x[i]);
        v.pb (y[i]);
    }
    int m = (n + 1) / 2;
    int ans = n + 1;
    for (int i = 0; i < sz (v); i++)
        if (all[v[i]] >= m) ans = min (ans, max (0, m - cur[v[i]]));
    if (ans > n) printf ("-1\n"); else printf ("%d\n", ans);
    return 0;
}