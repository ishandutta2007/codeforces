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
vector<pair<int, ii> > v;
int k;

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v.pb (mp (i + j + 1, mp (i, j)));
    sort (all (v));
    int ans = 0;
    for (int i = k - 1; i >= 0; i--) ans += v[i].fi;
    printf ("%d\n", ans);
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j <= v[i].se.se; j++)
            printf ("(%d,%d) ", 1, j + 1);
        for (int j = 1; j <= v[i].se.fi; j++)
            printf ("(%d,%d) ", j + 1, v[i].se.se + 1);
        printf ("\n");
    }
    return 0;
}