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

char h[50];

pair<int, string> v[100000];
int bon[100000];

bool l1 (pair<int, string> a, pair<int, string> b) {
    re a.fi > b.fi || a.fi == b.fi && a.se < b.se;
}

int main () {
    scanf ("%d", &n);
    gets (h);
    for (int i = 0; i < n; i++) {
        gets (h);
        stringstream in (h);
        in >> v[i].se >> v[i].fi;
    }
    sort (v, v + n, l1);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) scanf ("%d", &bon[i]);
    sort (bon, bon + n);
    reverse (bon, bon + n);
    string me;
    cin >> me;
    int it;
    for (int i = 0; i < n; i++)
        if (v[i].se == me)
            it = i;
    int high = 0, low = 0;
    int tmp = 1, tmp2 = n - 1;
    for (int i = 0; i < n; i++)
        if (i != it)
            if (v[i].fi > v[it].fi + bon[0] || v[i].fi == v[it].fi + bon[0] && v[i].se < v[it].se) {
                high++;
                tmp++;
            } else
            if (v[i].fi + bon[tmp2] < v[it].fi + bon[0] || v[i].fi + bon[tmp2] == v[it].fi + bon[0] && v[i].se > v[it].se) {
                tmp2--;
            }
    high += tmp2 - tmp + 1;
    tmp = 0; tmp2 = n - 2;
    for (int i = n - 1; i >= 0; i--)
        if (i != it)
            if (v[i].fi + bon[tmp] > v[it].fi + bon[n - 1] || v[i].fi + bon[tmp] == v[it].fi + bon[n - 1] && v[i].se < v[it].se) {
                low++;
                tmp++;
            }
    printf ("%d %d\n", high + 1, low + 1);
    return 0;
}