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

const int N = 5000000;

int n;
int m;

ii q[N];
int was[3010][3010];
int p[3010];
int s[3010];
int f[3010];
int k;

int main () {
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    s[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        s[i] = s[i + 1] + p[i];
        f[i] = f[i + 1] | int (p[i] == 100);
    }   
    int l = 0, r = 1;
    q[0] = mp (0, 1);
    was[0][1] = 1;
    while (l < r) {
        int x = q[l].fi;
        int y = q[l].se;
        l++;
        if (y < n && was[x][y] <= k) {
            if (p[x] < 100 && s[y] > 0 && !was[y][y + 1]) {
                was[y][y + 1] = was[x][y] + 1;
                q[r++] = mp (y, y + 1);
            }
            if (p[x] > 0 && !f[y] && !was[x][y + 1]) {
                was[x][y + 1] = was[x][y] + 1;
                q[r++] = mp (x, y + 1);
            }
            if (p[x] > 0 && s[y] > 0 && !was[y + 1][y + 2]) {
                was[y + 1][y + 2] = was[x][y] + 1;
                q[r++] = mp (y + 1, y + 2);
            }
        }
    }
    printf ("%d\n", r);
    return 0;
}