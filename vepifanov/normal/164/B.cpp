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
int x[2000000], f[1000000];

int get (int a, int b) {
    if (a > b) b += m;
    re b - a;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < 1000000; i++) f[i] = -1;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]); x[i]--;
        x[n + i] = x[i];
    }
    for (int i = 0; i < m; i++) {
        int y;
        scanf ("%d", &y); y--;
        f[y] = i;
    }
    int l = 0, r = 0, y = -1, len = 0, cnt = 0;
    int ans = 0;
    while (r < 2 * n) {
        if (f[x[r]] == -1) {
            l = r + 1;
            y = -1;
            len = 0;
            cnt = 0;
        } else {
            if (y == -1) {                          
                y = f[x[r]];
                len = 0;
                cnt = 1;
            } else {
                len += get (y, f[x[r]]);
                y = f[x[r]];
                cnt++;
                while (len >= m) {
                    len -= get (f[x[l]], f[x[l + 1]]);
                    cnt--;
                    l++;
                }
            }
        }
        ans = max (ans, cnt);
        r++;
    }
    printf ("%d\n", min (ans, n));
    return 0;
}