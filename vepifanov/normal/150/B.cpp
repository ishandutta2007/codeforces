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

const int mod = 1000000000 + 7;

int n;
int m, k;
int g[2000][2000];
int was[2000];

int go (int x) {
    was[x] = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i] && !was[i])
            go (i);
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i + k <= n; i++)
        for (int l = i, r = i + k - 1; l < r; l++, r--)
            g[l][r] = g[r][l] = 1;
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            ans = ((ll)ans * m) % mod;
            go (i);
        }   
    printf ("%d\n", ans);
    return 0;
}