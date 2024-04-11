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
int m, tt, k;

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int tt;
    scanf ("%d%d", &tt, &k);
    for (int i = 0; i < tt; i++) {
        scanf ("%d%d", &n, &m);
        int res;
        if (k == 1) {
            res = int (n % 2 == 0 || m % 2 == 0);
        } else {
            int tmp = min (n, m) / (k + 1);
            n -= tmp * (k + 1);
            m -= tmp * (k + 1);
            res = 1;
            if (n > 0 && m > 0) res = (n ^ m ^ tmp) & 1;
        }
        if (res) printf ("+\n"); else printf ("-\n");
    }
    return 0;
}