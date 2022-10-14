
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
 
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
 
typedef long long ll;
using namespace std;
#define MAXN 300500
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define N 5037
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[N + 5], st[N + 5], lc[N + 5];
vector<ll> g[N + 5], f, fg;
vector<pair<vector<ll>, ll> > ff;
set<vector<ll> > sf;
ll calc(ll j, ll i, ll p, ll s, ll cur, ll pcur) {
    for (int k = j; k < i; k++) {
        cur = min(cur, lc[k]);
        if (cur >= pcur) {
            s += cur * a[k+1];
        } else {
            s += (2 * cur - pcur) * a[k+1];
        }
    }
 
    cur = pcur;
    for (int k = j - 1; k >= p + 1; k--) {
        cur = min(cur, lc[k]);
        if (cur >= pcur) {
            s += cur * a[k];
        } else {
            s += (2 * cur - pcur) * a[k];
        }
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll sum = 0;
    ll x = 0;
    for (int i = 0; i < C; i++) {
        f.push_back(0);
    }
    for (int i = 1; i <= N; i++) {
        ll y = 0;
        ll z = i;
        for (int j = 2; j <= i; j++) {
            while (z % j == 0) {
                y++;
                z /= j;
                f.push_back(j);
            }
        }
        sort(f.begin(), f.end());
        reverse(f.begin(), f.end());
        while (f.size() > C) {
            f.pop_back();
        }
        x += y;
        sum += x;
        st[i] = x;
        g[i] = f;
    }
 
    long long cur_ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= N; i++) {
        cur_ans += 1LL * a[i] * st[i];
    }
    ll z = 0;
    for (int i = 1; i < N; i++) {
        ll lcp = 0;
        for (int j = 0; j < C; j++) {
            if (g[i][j] != g[i+1][j]) {
                lcp = j;
                break;
            }
        }
        lc[i] = lcp;
        z += lcp;
    }
 
    ll ss = 0;
    ll p = 0;
    ll xx = 0;
    for (int i = 1; i <= N; i++) {
        if (lc[i] == 0) {
            ll fucked = n;
            ll mx = 0;
            for (int j = p + 1 ; j <= i; j++) {
                fucked -= a[j];
                mx = max(mx, lc[j]);
            }
            for (int j = p+1; j <= i; j++) {
                ll s, cur, pcur;
                s = -fucked * lc[j] + min(st[j], lc[j]) * a[j];
                cur = pcur = lc[j];
                s = calc(j, i, p, s, cur, pcur);
 
                ss = max(ss, s);
 
                
 
 
                s = -fucked * st[j] + st[j] * a[j];
                ll prs = s;
                cur = pcur = st[j];
                s = calc(j, i, p, s, cur, pcur);
                /*if (s > 0) {
                    cout << i << " " << j << " " << p << " " << s << " " << st[j] << " " << prs << "\n";
                }*/
                ss = max(ss, s);
            }
            p = i;
        }
    }
    cout << cur_ans - ss << "\n";
 
 
    return 0;
 
}