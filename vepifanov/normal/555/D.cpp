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
ii v[200000];
int w[200000];
int q[10000000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].fi);
        v[i].se = i;
    }
    sort (v, v + n);
    for (int i = 0; i < n; i++) w[v[i].se] = i;
    for (int i = 0; i < m; i++) {
        int a, l, dir = 1;
        scanf ("%d%d", &a, &l); a = w[a - 1];
        int o = 0;
        while (true) {
            q[o++] = a;
            if (o > 2 && q[o - 3] == q[o - 1]) {
                l %= 2 * abs (v[q[o - 1]].fi - v[q[o - 2]].fi);
            }
            if ((a + 1 == n || v[a + 1].fi - v[a].fi > l) && (a == 0 || v[a].fi - v[a - 1].fi > l)) {
                printf ("%d\n", v[a].se + 1);
                break;
            }
            while (true) {
                if (dir) {
                    dir ^= 1;
                    int L = a, R = n;
                    while (R - L > 1) {
                        int s = (L + R) / 2;
                        if (v[s].fi - v[a].fi <= l) L = s; else R = s; 
                    }
                    if (L == a) continue;
                    l -= v[L].fi - v[a].fi;
                    a = L;
                } else {
                    dir ^= 1;
                    int L = -1, R = a;
                    while (R - L > 1) {
                        int s = (L + R) / 2;
                        if (v[a].fi - v[s].fi <= l) R = s; else L = s;
                    }
                    if (R == a) continue;
                    l -= v[a].fi - v[R].fi;
                    a = R;
                }
                break;
            }   
        }
    }
    return 0;
}