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

int n, d, a, b;
int m;
ii v[100000];
vi res;

int main () {
    scanf ("%d%d%d%d", &n, &d, &a, &b);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        v[i] = mp (x * a + y * b, i);
    }
    sort (v, v + n);
    for (int i = 0; i < n; i++)
        if (v[i].fi <= d) {
            res.pb (v[i].se);
            d -= v[i].fi;
        } else break;
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d ", res[i] + 1);
    printf ("\n");
    return 0;
}