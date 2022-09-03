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
#define prev PREV
                         
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
int w, h;
set<int> vw, vh;
multiset<int> lw, lh;

int main () {
    scanf ("%d%d%d", &w, &h, &n);
    vw.insert (0);
    vw.insert (w);
    vh.insert (0);
    vh.insert (h);
    lw.insert (w);
    lh.insert (h);
    for (int i = 0; i < n; i++) {
        char h[5];
        int x;
        scanf (" %s%d", h, &x);
        if (h[0] == 'H') {
            set<int>::iterator it = vh.lower_bound (x);
            int y2 = *it;
            it--;
            int y1 = *it;
            lh.erase (lh.find (y2 - y1));
            lh.insert (x - y1);
            lh.insert (y2 - x);
            vh.insert (x);
        } else {
            set<int>::iterator it = vw.lower_bound (x);
            int y2 = *it;
            it--;
            int y1 = *it;
            lw.erase (lw.find (y2 - y1));
            lw.insert (x - y1);
            lw.insert (y2 - x);
            vw.insert (x);
        }
        printf ("%I64d\n", (ll)(*lw.rbegin ()) * (*lh.rbegin ()));
    }
    return 0;
}