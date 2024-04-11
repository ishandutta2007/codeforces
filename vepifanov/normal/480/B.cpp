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
int x, y;
int l;
int f[100001];
set<int> all;
int pos;

int can (int h) {
    for (int i = 0; i < n; i++)
        if (all.count (f[i] + h)) {
            pos = f[i];
            re 1;
        }
    re 0;
}

int can2 (int h) {
    for (int i = n - 1; i >= 0; i--)
        if (all.count (f[i] - h)) {
            pos = f[i];
            re 1;
        }
    re 0;
}

int main () {
    scanf ("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &f[i]);
        all.insert (f[i]);
    }
    if (can (x) && can (y)) printf ("0\n"); else
    if (can (x)) printf ("1\n%d\n", y); else
    if (can (y)) printf ("1\n%d\n", x); else
    if (can (x + y)) printf ("1\n%d\n", pos + x); else
    if (can (y - x) && pos + y < l) printf ("1\n%d\n", pos + y); else
    if (can2 (y - x) && pos - y > 0) printf ("1\n%d\n", pos - y); else printf ("2\n%d %d\n", x, y);
    return 0;
}