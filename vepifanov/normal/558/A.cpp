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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
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
ii v[100];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d%d", &v[i].fi, &v[i].se);
    sort (v, v + n);
    int l, r;
    if (v[0].fi > 0) { l = -1; r = 0; } else
    if (v[n - 1].fi < 0) { l = n - 1; r = n; } else {
        for (int i = 0; i + 1 < n; i++)
            if (v[i].fi < 0 && v[i + 1].fi > 0) {
                l = i;
                r = i + 1;
                break;
            }
    }
    int ans1 = 0, ans2 = 0;
    {
        int ll = l, rr = r;
        while (true) {
            if (ll >= 0) ans1 += v[ll].se; else break;
            ll--;
            if (rr < n) ans1 += v[rr].se; else break;
            rr++;
        }  
    }
    {
        int ll = l, rr = r;
        while (true) {
            if (rr < n) ans2 += v[rr].se; else break;
            rr++;
            if (ll >= 0) ans2 += v[ll].se; else break;
            ll--;
        }  
    }
    printf ("%d\n", max (ans1, ans2));
    return 0;
}