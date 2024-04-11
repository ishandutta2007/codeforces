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
#include <cassert>

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
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 1 << 19;

int n;
int m;
ii tree[2 * N + 10];
int w[N];
int s[N];
map<int, int> all[N];
int o = 0;
ll ans = 0;

ii build (int x, int l, int r) {
    if (l == r) re tree[x] = mp (w[l], l);
    int s = (l + r) / 2;
    re tree[x] = max (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
}

ii get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re mp (-1e9, 0);
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re max (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int go (int l, int r) {
    if (l > r) {
        int cur = o++;
        all[cur][s[l]] = 1;
//      printf ("%d %d\n%d - %d\n", l + 1, r + 1, s[l], 1);
        re cur;
    }
    int s = get (0, 0, n - 1, l, r).se;
    int ws = w[s] % m;
    int a = go (l, s - 1);
    int b = go (s + 1, r);
    int cur;
    if (sz (all[a]) < sz (all[b])) {
        for (auto x : all[a]) {
            int y = x.fi - ws;
            if (y < 0) y += m;
            auto it2 = all[b].find (y);
            if (it2 != all[b].end ()) ans += (ll)x.se * it2->se;
        }
        for (auto x : all[a]) all[b][x.fi] += x.se;
        all[a].clear ();
        ans--;
        cur = b;
    } else {
        for (auto x : all[b]) {
            int y = ws + x.fi;
            if (y >= m) y -= m;
            auto it2 = all[a].find (y);
            if (it2 != all[a].end ()) ans += (ll)x.se * it2->se;
        }
        for (auto x : all[b]) all[a][x.fi] += x.se;
        all[b].clear ();
        ans--;
        cur = a;
    }
/*  printf ("%d %d = %I64d | %d\n", l + 1, r + 1, ans, ws);
    for (int i = l; i <= r + 1; i++)
        printf ("%d ", ::s[i]);
    printf ("\n");  
    for (auto x : all[cur]) printf ("%d - %d\n", x.fi, x.se);
    assert (ans >= 0);*/
    re cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &w[i]);
    s[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        s[i] = (s[i + 1] + w[i]) % m;
    build (0, 0, n - 1);
    ans = 0;
    go (0, n - 1);
    cout << ans << endl;
    cerr << clock () << endl;
    return 0;
}