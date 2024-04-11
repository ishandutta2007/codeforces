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

int get (int a, int b) {
    re int (b > 0);
}

int good (int n, int m, int k) {
    re int (n <= m + int (k != 0) && m <= 2 * (n + int (k != 1)));
}

int main () {
    scanf ("%d%d", &n, &m);
    if (good (n, m, 2)) {
        int last = -1;
        while (n > 0 || m > 0) {
            int ok = 0;
            for (int a = min (n, 1); a >= 0 && !ok; a--)
                for (int b = min (m, 2); a + b > 0 && !ok; b--) {
                    if (int (a == 0) == last) continue;
                    if (good (n - a, m - b, get (a, b))) {
                        ok = 1;
                        for (int t = 0; t < a; t++) printf ("0");
                        for (int t = 0; t < b; t++) printf ("1");
                        n -= a;
                        m -= b;
                        last = get (a, b);
                    }
                }
        }
        printf ("\n");
    } else {
        printf ("-1\n");
        re 0;
    }
    return 0;
}