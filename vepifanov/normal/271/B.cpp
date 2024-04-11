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

const int MAX = 200000;

int n;
int m;
int w[MAX + 1], f[MAX + 1];
int r[500], c[500];

int main () {
        f[1] = 1;
    for (int i = 2; i <= MAX; i++)
        if (!f[i]) {
            if (i <= MAX / i)
                for (int j = i * i; j <= MAX; j += i)
                    f[j] = 1;
        }
    int cur = MAX;
    for (int i = MAX; i > 0; i--) {
        if (!f[i]) cur = i;
        w[i] = cur - i;
    }
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x);
            r[i] += w[x];
            c[j] += w[x];
        }
    int ans = 2e9;
    for (int i = 0; i < n; i++) ans = min (ans, r[i]);
    for (int i = 0; i < m; i++) ans = min (ans, c[i]);
    printf ("%d\n", ans);
    return 0;
}