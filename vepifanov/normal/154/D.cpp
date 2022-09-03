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
int d, x1, x2, a, b;

int main () {
    scanf ("%d%d%d%d", &x1, &x2, &a, &b);
    d = x2 - x1;
    if (a <= 0 && b >= 0) {
        if (d >= a && d <= b) printf ("FIRST\n%d\n", x1 + d); else printf ("DRAW\n");
    } else {
        int rev = 1;
        if (a < 0) {
            rev = -1;
            d = -d;
            swap (a, b);
            a = -a;
            b = -b;
        }
        if (d < 0) printf ("DRAW\n"); else {
            if (d % (a + b) == 0) printf ("SECOND\n"); else {
                d %= (a + b);
                if (d < 0) d += a + b;
                if (d >= a && d <= b) printf ("FIRST\n%d\n", x1 + rev * d); else printf ("DRAW\n");
            }
        }
    }
    return 0;
}