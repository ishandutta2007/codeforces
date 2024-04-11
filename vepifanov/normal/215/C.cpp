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
int m, s;

int main () {
    scanf ("%d%d%d", &n, &m, &s);
    ll ans = 0;
    for (int p = 1; p <= n; p += 2)
        for (int q = 1; q <= m; q += 2) {
            int cur = p * q, tmp = (n - p + 1) * (m - q + 1);
            if (cur >= s && (cur - s) % 4 == 0) {
                cur = (cur - s) / 4;
                if (cur == 0) ans += (ll)tmp * ((p / 2 + 1) * (q / 2 + 1) * 2 - 1); else
                for (int a = 1; a <= p / 2; a++)
                    if (cur % a == 0 && cur / a <= q / 2)
                        ans += tmp * 2;
            }
        }   
    printf ("%I64d\n", ans);
    return 0;
}