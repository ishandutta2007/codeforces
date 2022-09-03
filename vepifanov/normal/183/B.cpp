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
#define next NEXT
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
int m, u;
int x[250], y[250];
int res[1000001];

int main () {
        scanf ("%d%d", &n, &m);
        for (int i = 0; i < m; i++) scanf ("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= n; i++) res[i] = 1;
        for (int i = 0; i < m; i++)
                for (int j = i + 1; j < m; j++) {
                        if (y[j] == y[i] || (ll)(x[j] - x[i]) * y[i] % (y[j] - y[i]) != 0) continue;
                        ll t = x[i] - (ll)(x[j] - x[i]) * y[i] / (y[j] - y[i]);
                        if (t >= 1 && t <= n) {
                                int tmp = 0;
                                for (int k = 0; k < m; k++)
                                        if ((ll)(x[i] - x[k]) * (y[j] - y[k]) - (ll)(x[j] - x[k]) * (y[i] - y[k]) == 0)
                                                tmp++;
                                res[t] = max (res[t], tmp);
                        }
                }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += res[i];
        printf ("%d\n", ans);
        return 0;
}