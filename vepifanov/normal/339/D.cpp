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
int tree[1 << 20];

int upd (int t, int x, int l, int r, int y, int z) {
    if (y < l || y > r) re tree[x];
    if (l == r) re tree[x] = z;
    int s = (l + r) / 2;
    upd (t ^ 1, x * 2 + 1, l, s, y, z);
    upd (t ^ 1, x * 2 + 2, s + 1, r, y, z);
    if (!t) tree[x] = tree[x * 2 + 1] ^ tree[x * 2 + 2]; else tree[x] = tree[x * 2 + 1] | tree[x * 2 + 2];
    re tree[x];
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < (1 << n); i++) {
        int x;
        scanf ("%d", &x);
        upd (n & 1, 0, 0, (1 << n) - 1, i, x);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--;
        printf ("%d\n", upd (n & 1, 0, 0, (1 << n) - 1, a, b));
    }
    return 0;
}