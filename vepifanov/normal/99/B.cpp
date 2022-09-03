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
ii x[1000];

int main () {
    scanf ("%d", &n);   
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i].fi);
        x[i].se = i + 1;
    }
    sort (x, x + n);
    if (x[0].fi == x[n - 1].fi) printf ("Exemplary pages.\n"); else {
        int s = (x[n - 1].fi - x[0].fi) / 2;
        int a = x[0].se, b = x[n - 1].se;
        x[0].fi += s;
        x[n - 1].fi -= s;
        sort (x, x + n);
        if (x[0].fi == x[n - 1].fi) printf ("%d ml. from cup #%d to cup #%d.\n", s, a, b); else printf ("Unrecoverable configuration.\n");
    }
    return 0;
}