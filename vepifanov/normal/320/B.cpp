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
int a[100], b[100], was[100];
int ct;

int go (int x, int y) {
    if (x == y) re 1;
    if (was[x] == ct) re 0;
    was[x] = ct;
    for (int i = 0; i < m; i++)
        if (a[i] < a[x] && a[x] < b[i] || a[i] < b[x] && b[x] < b[i])
            if (go (i, y))
                re 1;
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf ("%d", &t);
        if (t == 1) {
            scanf ("%d%d", &a[m], &b[m]);
            m++;
        } else {
            int a, b;
            scanf ("%d%d", &a, &b); a--; b--;
            ct++;
            if (go (a, b)) printf ("YES\n"); else printf ("NO\n");
        }
    }
    return 0;
}