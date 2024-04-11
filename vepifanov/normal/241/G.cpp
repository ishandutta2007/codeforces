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
int x[500];
int p[500];

int can (int x1, int r1, int x2, int r2) {
    ll d = (ll)(x2 - x1) * (x2 - x1) + (ll)(r2 - r1) * (r2 - r1);
    if (d < (ll)(r1 + r2) * (r1 + r2)) re 0;
    re 1;
}

int main () {
    x[0] = 0;
    p[0] = 1000000;
    printf ("302\n");
    printf ("0 1000000\n");
    int n = 0;
    for (int i = 1; i <= 1000000 && n < 300; i++) {
        int r = 300 - n;
        int ok = 1;
        for (int j = 0; j <= n; j++)
            if (!can (x[j], p[j], i, r)) {
                ok = 0;
                break;
            }
        if (ok) {
            printf ("%d %d\n", i, r);
            n++;
            x[n] = i;
            p[n] = r;
        }
    }
    printf ("1000000 1000000\n");
    return 0;
}