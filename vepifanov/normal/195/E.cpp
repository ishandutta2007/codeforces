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
int m;

int root[100000];
int depth[100000];

ii get (int x) {
    if (root[x] == x) re mp (x, 0);
    ii tmp = get (root[x]);
    root[x] = tmp.fi;
    depth[x] = (tmp.se + depth[x]) % mod;
    re mp (root[x], depth[x]);
}

int main () {
    scanf ("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &m);
        for (int j = 0; j < m; j++) {
            int x, y;
            scanf ("%d%d", &x, &y); x--;
            if (y < 0) y += mod;
                        ii tmp = get (x);
                        root[tmp.fi] = i;
                        depth[tmp.fi] = (tmp.se + y) % mod;
                        ans = (ans + depth[tmp.fi]) % mod;
        }
        root[i] = i;
        depth[i] = 0;
    }
    printf ("%d\n", ans);
    return 0;
}