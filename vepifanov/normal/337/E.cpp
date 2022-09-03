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
int res[1 << 8];
int ans[1 << 8];
ll x[8];
int y[8];
vector<ll> v[8];

int calc (ll x) {
    int ans = 0;
    for (int i = 2; (ll)i * i <= x; i++)
        while (x % i == 0) {
            x /= i;
            ans++;
        }
    if (x > 1) ans++;
    re ans;
}

int go (int);

int gen (int i, vi w, int mask, ll cx, int j) {
    if (i == -1) {
        int cur = 1;
        for (int k = 0; k < sz (v[j]); k++)
            while (cx % v[j][k] == 0) {
                cur++;
                cx /= v[j][k];
            }       
        for (int k = 0; k < sz (w); k++) cur += go (w[k]);
        re cur;
    }
    int cur = 1e9;
    if ((mask >> i) & 1) {
        for (int t = 0; t < sz (w); t++) {
            w[t] ^= 1 << i;
            cur = min (cur, gen (i - 1, w, mask, cx, j));
            w[t] ^= 1 << i;
        }
        if (cx % x[i] == 0) {
            w.pb (1 << i);
            cur = min (cur, gen (i - 1, w, mask, cx / x[i], j));
            w.pop_back ();
        }
    } else cur = gen (i - 1, w, mask, cx, j);
    re cur;
}

int go (int mask) {
    if (mask == 0) re 0;
    if (res[mask]) re res[mask];
    int pos = -1;
    for (int i = 0; i < n; i++)
        if ((mask >> i) & 1)
            pos = i;
    vi w;
    res[mask] = gen (pos - 1, w, mask - (1 << pos), x[pos], pos);
//  printf ("%d = %d\n", mask, res[mask]);
    re res[mask];
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort (x, x + n);
    int good = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        ll z = x[i];
        for (int j = 2; (ll)j * j <= z; j++)
            if (z % j == 0) {
                v[i].pb (j);
                while (z % j == 0) {
                    y[i]++;
                    z /= j;
                }
            }
        if (z > 1) {
            y[i]++;
            v[i].pb (z);
        }
        res[1 << i] = ans[1 << i] = y[i] + 1;
        if (y[i] == 1) {
            cnt++;
            for (int j = i + 1; j < n; j++)
                if (x[j] % x[i] == 0) {
                    cnt--;
                    break;
                }
        } else good |= 1 << i;
    }
    ans[0] = 0;
    for (int i = 1; i <= good; i++) {
        if ((i & good) != i) continue;
        ans[i] = 1e9;
        for (int j = i; j > 0; j = (j - 1) & i) {
//          printf ("%d %d = %d %d = %d\n", i, j, ans[i - j], go (j));
            ans[i] = min (ans[i], ans[i - j] + go (j));
        }
    }
    if (good == 0) printf ("%d\n", n + int (n > 1)); else
    printf ("%d\n", min (ans[good] + 1 + cnt, go (good) + int (cnt > 0) + cnt));
    return 0;
}