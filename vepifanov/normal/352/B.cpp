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
vi w[100001];
vii res;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        w[x].pb (i);
    }
    for (int i = 1; i <= 100000; i++)
        if (sz (w[i]) == 1)
            res.pb (mp (i, 0));
        else
        if (sz (w[i]) > 1) {
            int k = w[i][1] - w[i][0], ok = 1;
            for (int j = 1; j + 1 < sz (w[i]); j++)
                if (w[i][j + 1] - w[i][j] != k)
                    ok = 0;
            if (ok) res.pb (mp (i, k));
        }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi, res[i].se);
    return 0;
}