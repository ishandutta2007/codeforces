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
int a, b;

ll get (int l, int r, int m) {
    ll x = a + (ll)(l - 1) * b;
    ll y = a + (ll)(r - 1) * b;
    ll sum = (x + y) * (r - l + 1) / 2;
    re max ((sum + m - 1) / m, y);
}                   

int main () {
    scanf ("%d%d%d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        int x, t, m;
        scanf ("%d%d%d", &x, &t, &m);
        if (get (x, x, m) > t) printf ("-1\n"); else {
            int l = x, r = x + 2e6;
            while (r - l > 1) {
                int s = (l + r) / 2;
                if (get (x, s, m) > t) r = s; else l = s;
            }
            printf ("%d\n", l);
        }
    }
    return 0;
}