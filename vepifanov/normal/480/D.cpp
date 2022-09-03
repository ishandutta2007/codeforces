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
#define next NEXT
                         
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
int S;
int l[502];
int r[502];
int w[502];
int v[502];
int s[502];
int p[502];
int res[502][1001];
int res2[501][1001];
int next[502];

bool ls (int a, int b) {
    if (l[a] != l[b])
        re l[a] < l[b];
    if (r[a] != r[b])
        re r[a] > r[b];
    if (w[a] + s[a] != w[b] + s[b]) 
        re w[a] + s[a] > w[b] + s[b];
    re false;
}

int main () {
    scanf ("%d%d", &n, &S);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d%d%d", &l[i], &r[i], &w[i], &s[i], &v[i]);
        p[i] = i;
    }
    l[n] = 0;
    r[n] = 2 * n;
    w[n] = 2000;
    s[n] = 2000;
    v[n] = 0;
    p[n] = n;
    sort (p, p + n + 1, ls);
    for (int i = 0; i <= n; i++) {
        next[i] = n + 1;
        for (int j = i + 1; j <= n; j++)
            if (l[p[j]] >= r[p[i]]) {
                next[i] = j;
                break;
            }
    }
    for (int i = n; i >= 0; i--) {
        memset (res2, 0, sizeof (res2));
        for (int j = n; j > i; j--)
            for (int k = 0; k <= S; k++) {
                res2[j][k] = res2[j + 1][k];
                if (r[p[j]] <= r[p[i]] && k >= w[p[j]])
                    res2[j][k] = max (res2[j][k], res[j][min (k - w[p[j]], s[p[j]])] + res2[next[j]][k] + v[p[j]]);
//              printf ("%d = %d %d = %d %d = %d = %d\n", i, l[p[i]], r[p[i]], l[p[j]], r[p[j]], k, res2[j][k]);
            }
        for (int k = 0; k <= S; k++)
            res[i][k] = res2[i + 1][k];
    }
    printf ("%d\n", res[0][S]);
    return 0;
}