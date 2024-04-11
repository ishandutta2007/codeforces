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
int l, r, p;

int get (int m, int a, int d) {
    int t = a / d;
    re ((ll)(m + 1) * t - (ll)t * (t + 1) * d / 2) % p;
}

int main () {
    scanf ("%d%d", &n, &m);
    scanf ("%d%d%d", &l, &r, &p);
    int ans = 0;
    if (l <= 1 && r >= 1) ans = ((ll)2 * n * m + n + m) % p;
    for (int a = 1; a <= n; a++) {
        int b0, b1;
        {
            int cl = 0, cr = m + 1;
            while (cr - cl > 1) {
                int s = (cl + cr) / 2;
                if ((ll)a * a + (ll)s * s < (ll)l * l) cl = s; else cr = s;
            }
            b0 = cl;
        }
        {
            int cl = 0, cr = m + 1;
            while (cr - cl > 1) {
                int s = (cl + cr) / 2;
                if ((ll)a * a + (ll)s * s <= (ll)r * r) cl = s; else cr = s;
            }
            b1 = cl;
        }
        if (b0 < b1) {
            int A = a;
            vi v;
            for (int t = 2; t * t <= A; t++)
                if (A % t == 0) {
                    v.pb (t);
                    while (A % t == 0) A /= t;
                }
            if (A > 1) v.pb (A);
            int cur = 0;
            for (int mask = 0; mask < (1 << sz (v)); mask++) {
                int tmp = 1, q = 1;
                for (int t = 0; t < sz (v); t++)
                    if ((mask >> t) & 1) {
                        tmp *= v[t];
                        q = -q;
                    }
                cur = ((ll)cur + q * get (m, b1, tmp) - q * get (m, b0, tmp)) % p;
                if (cur < 0) cur += p;
            }
            ans = (ans + (ll)2 * cur * (n - a + 1)) % p;
        }
    }
    printf ("%d\n", ans);
    return 0;
}