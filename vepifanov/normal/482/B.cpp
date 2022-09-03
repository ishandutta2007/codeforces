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
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <functional>

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
#define next NEXT
#define _bit(x,y) ((x >> y) & 1)
#define bin(x,y) (bitset<y>) x
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const long double pi = acos (-1.0);

#define filename ""

int n;
int m;                                            

const int N = 3 * 1e5;

int t[N + 10];
int w[N + 10];
int l[100000 + 10], r[100000 + 10], q[100000 + 10];
int ans[100000 + 10];

void push (int x, int l, int r) {
    if (l != r) {
        t[2 * x + 1] |= t[x];
        t[2 * x + 2] |= t[x];
    }
}

int build (int x, int lc, int rc)
{
    if (lc == rc) { 
        ans[lc] = t[x];
            re w[x] = ans[lc]; 
    } 
    push (x, lc, rc);
    int mc = (lc + rc) / 2; 
    re w[x] = build (2 * x + 1, lc, mc) & build (2 * x + 2, mc + 1, rc);
}


int get (int x, int lc, int rc, int l, int r)
{
    if (lc > r || rc < l) re (1 << 30) - 1;
    if ((lc >= l && rc <= r)) re w[x];
    int mc = (lc + rc) / 2;
    re get (2 * x + 1, lc, mc, l, r) & get (2 * x + 2, mc + 1, rc, l, r);   
}

void add (int x, int lc, int rc, int l, int r, int y)
{
    if (lc > r || rc < l) re ; 
    if (lc >= l && rc <= r) { t[x] |= y; re ; }
    push (x, lc, rc);
    int mc = (lc + rc) / 2;
    add (2 * x + 1, lc, mc, l, r, y);
    add (2 * x + 2, mc + 1, rc, l, r, y);
    re ;
}

int main () {
//  freopen (filename".in", "r", stdin);
//  freopen (filename".out", "w", stdout);  
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {       
        scanf ("%d %d %d", &l[i], &r[i], &q[i]); l[i] --; r[i] --;
        add (0, 0, n - 1, l[i], r[i], q[i]);
    }
    build (0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        if (q[i] != get (0, 0, n - 1, l[i], r[i])) {
            printf ("NO\n");
            re 0;
        }
    }
    printf ("YES\n");
    for (int i = 0; i < n; i++) printf ("%d ", ans[i]);
    return 0;
}