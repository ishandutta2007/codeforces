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
int m, k;

ll ans;
set<ii> an, anp;
int x[100000];

int go () {
    an.clear ();
    anp.clear ();
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] >= 0) cur += x[i]; else {
            cur -= x[i];
            anp.insert (mp (-x[i], i));
            if (sz (anp) > k) {
                ii tmp = *anp.begin();
                anp.erase (anp.begin ());
                cur -= tmp.fi * 2;
                tmp.fi = -tmp.fi;
                an.insert (tmp);
            }
        }
        if (i >= m - 1) {
            ans = max (ans, cur);
            int j = i - m + 1;
            if (x[j] >= 0) cur -= x[j]; else {
                if (anp.find (mp (-x[j], j)) != anp.end ()) {
                    cur += x[j];
                    anp.erase (mp (-x[j], j));
                    if (sz (an) > 0) {
                        ii tmp = *an.begin ();
                        an.erase (an.begin ());
                        cur -= tmp.fi * 2;
                        tmp.fi = -tmp.fi;
                        anp.insert (tmp);
                    }
                } else {
                    cur -= x[j];
                    an.erase (mp (x[j], j));
                }
            }
        }
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    scanf ("%d", &k);
    ans = 0;
    go ();
    for (int i = 0; i < n; i++) x[i] = -x[i];
    go ();
    cout << ans << endl;
    return 0;
}