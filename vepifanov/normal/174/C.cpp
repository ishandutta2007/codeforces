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

ii q[100000];
vii res;

int main () {
    scanf ("%d", &n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf ("%d", &a);
        while (r > 0 && q[r - 1].fi > a) {
            int tmp = q[r - 1].fi - a;
            if (r > 1) tmp = min (tmp, q[r - 1].fi - q[r - 2].fi);
            for (int j = 0; j < tmp; j++) res.pb (mp (q[r - 1].se, i));
            q[r - 1].fi -= tmp;
            if (r > 1 && q[r - 2].fi == q[r - 1].fi) r--; else break;
        }
        if (r == 0 || q[r - 1].fi < a) q[r++] = mp (a, i + 1);
    }
    while (r > 0) {
        int tmp = q[r - 1].fi;
        if (r > 1) tmp = min (tmp, q[r - 1].fi - q[r - 2].fi);
        for (int j = 0; j < tmp; j++) res.pb (mp (q[r - 1].se, n));
        r--;
    }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi, res[i].se);
    return 0;
}