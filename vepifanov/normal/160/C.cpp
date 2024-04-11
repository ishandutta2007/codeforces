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
ll m;

int x[100000];
vii v;

int main () {
    scanf ("%d%I64d", &n, &m); m--;
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || x[i - 1] != x[i]) cur = 0;
        cur++;
        if (i + 1 == n || x[i + 1] != x[i]) v.pb (mp (cur, x[i]));
    }
    for (int i = 0; i < sz (v); i++)
        if ((ll)v[i].fi * n > m) {
            for (int j = 0; j < sz (v); j++)
                if ((ll)v[i].fi * v[j].fi > m) {
                    printf ("%d %d\n", v[i].se, v[j].se);
                    re 0;
                } else m -= (ll)v[i].fi * v[j].fi;
        } else m -= (ll)v[i].fi * n;
    return 0;
}