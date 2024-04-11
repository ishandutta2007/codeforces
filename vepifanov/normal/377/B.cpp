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
int s;
int res[100000];
pair<int, ii> v[100000];
ii a[100000];
set<ii> all;

int can (int h) {
    int cur = 0;
    all.clear ();
    for (int i = 0, j = 0; i < m && cur <= s; i += h) {
        while (j < n && v[j].fi >= a[i].fi) {
            all.insert (v[j].se);
            j++;
        }
        if (all.empty ()) re 0;
        ii tmp = *all.begin ();
        all.erase (tmp);
        for (int k = i; k < i + h && k < m; k++) res[a[k].se] = tmp.se;
        cur += tmp.fi;
    }
    if (cur <= s) re 1;
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &a[i].fi);
        a[i].se = i;
    }   
    for (int i = 0; i < n; i++) scanf ("%d", &v[i].fi);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].se.fi);
        v[i].se.se = i;
    }   
    sort (a, a + m);
    reverse (a, a + m);
    sort (v, v + n);
    reverse (v, v + n);
    int l = 0, r = m;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (s)) r = s; else l = s;
    }
    if (can (r)) {
        printf ("YES\n");
        for (int i = 0; i < m; i++) printf ("%d ", res[i] + 1);
        printf ("\n");
    } else printf ("NO\n");
    return 0;
}