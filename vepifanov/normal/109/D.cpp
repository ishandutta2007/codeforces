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
vii res;

int cool (int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) re 0;
        x /= 10;
    }
    re 1;
}

int main () {
    scanf ("%d", &n);   
    int ok = 1, luck = -1;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        if (cool (x[i])) luck = i;
        if (i > 0 && x[i] < x[i - 1]) ok = 0;
    }
    if (ok) printf ("0\n"); else
    if (luck == -1) printf ("-1\n"); else {
        vii v;
        for (int i = 0; i < n; i++) v.pb (mp (x[i], i));
        sort (all (v));
        for (int i = 0; i < n; i++) y[v[i].se] = i;
        for (int i = 0; i < n; i++) {
            if (v[i].se != i && v[i].se != luck) {
                if (luck != i) {
                    int a = y[i];
                    int b = y[luck];
                    swap (v[a].se, v[b].se);
                    swap (y[i], y[luck]);
                    res.pb (mp (i, luck));
                    luck = i;
                }
                int j = v[i].se;
                int a = y[j];
                int b = y[luck];
                swap (v[a].se, v[b].se);
                swap (y[j], y[luck]);
                res.pb (mp (j, luck));
                luck = j;
            }
        }   
        printf ("%d\n", sz (res));
        for (int i = 0; i < sz (res); i++)
            printf ("%d %d\n", res[i].fi + 1, res[i].se + 1);
    }
    return 0;
}