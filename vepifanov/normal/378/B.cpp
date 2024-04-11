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
vector<pair<int, ii> > v, w;
int res[100000][2];

int main () {
    scanf ("%d", &n);
    m = n / 2;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        w.pb (mp (a, mp (0, i)));
        w.pb (mp (b, mp (1, i)));
        if (i >= m) {
            v.pb (mp (a, mp (0, i)));
            v.pb (mp (b, mp (1, i)));
        } else res[i][0] = res[i][1] = 1;
    }   
    sort (all (v));
    sort (all (w));
    for (int i = 0; i < n; i++)
        res[w[i].se.se][w[i].se.fi] = 1;
    for (int i = 0; i < n - 2 * m; i++)
        res[v[i].se.se][v[i].se.fi] = 1;
    for (int i = 0; i < n; i++) printf ("%d", res[i][0]);
    printf ("\n");
    for (int i = 0; i < n; i++) printf ("%d", res[i][1]);
    printf ("\n");
    return 0;
}