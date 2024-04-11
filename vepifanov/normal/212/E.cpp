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

vi v[5000];
int res[5001];
int can[5001];
int was[5000];
int ct;

int go (int x, int p) {
    was[x] = ct;
    int tmp = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i] != p && was[v[x][i]] != ct)
            tmp += go (v[x][i], x);
    re tmp;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }   
    memset (can, 0, sizeof (can));
    for (int i = 0; i < n; i++)
        if (sz (v[i]) > 1) {
            memset (res, 0, sizeof (res));
            res[0] = 1;
            for (int t = 0; t < sz (v[i]); t++) {
                ct++;
                int k = go (v[i][t], i);
                for (int l = n - 1; l >= 0; l--)
                    if (res[l])
                        res[l + k] = 1;
            }
            for (int l = 1; l< n; l++)
                can[l] |= res[l];
        }
    int ans = 0;
    for (int i = 1; i + 1 < n; i++)
        if (can[i])
            ans++;
    printf ("%d\n", ans);
    for (int i = 1; i + 1 < n; i++)
        if (can[i])
            printf ("%d %d\n", i, n - i - 1);
    return 0;
}