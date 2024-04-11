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
map<ii, int> all;
int was[100002];
int d[100002];
ii w[100002];
int q[100002];

int add (int x, int y) {
    if (all.find (mp (x, y)) != all.end ()) re all[mp (x, y)];
    w[m] = mp (x, y);
    all[mp (x, y)] = m++;
    re m - 1;
}

int get (int x, int y) {
    if (all.find (mp (x, y)) != all.end ()) re all[mp (x, y)];
    re -1;
}   

int main () {
    int x1, y1, x2, y2;
    scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
    int s = add (x1, y1);
    int t = add (x2, y2);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int r, a, b;
        scanf ("%d%d%d", &r, &a, &b);
        for (int j = a; j <= b; j++)
            add (r, j);
    }
    int l = 0, r = 1;
    q[0] = s;
    was[s] = 1;
    while (l < r) {
        int k = q[l++];
        int i = w[k].fi;
        int j = w[k].se;
        for (int a = -1; a <= 1; a++)
            for (int b = -1; b <= 1; b++) {
                int nk = get (i + a, j + b);
                if (nk != -1 && !was[nk]) {
                    was[nk] = 1;
                    d[nk] = d[k] + 1;
                    q[r++] = nk;
                }
            }
    }
    if (was[t]) printf ("%d\n", d[t]); else printf ("%d\n", -1);
    return 0;
}