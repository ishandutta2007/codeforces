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
pair<int, ii> v[100000];

int go (int x, int y) {
    if (x > 0) printf ("1 %d R\n", x);
    if (x < 0) printf ("1 %d L\n", -x);
    if (y > 0) printf ("1 %d U\n", y);
    if (y < 0) printf ("1 %d D\n", -y);
    re 0;
}

int main () {
    scanf ("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &v[i].se.fi, &v[i].se.se);
        v[i].fi = abs (v[i].se.fi) + abs (v[i].se.se);
        ans += 2 * int (v[i].se.fi != 0) + 2 * int (v[i].se.se != 0) + 2;
    }
    sort (v, v + n);
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++) {
        go (v[i].se.fi, v[i].se.se);
        printf ("2\n");
        go (-v[i].se.fi, -v[i].se.se);
        printf ("3\n");
    }
    return 0;
}