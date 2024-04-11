#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1505;
int a[maxn][maxn], b[maxn][maxn];
const ll mod[2] = {1000000009, 998244353};
const ll p[2] = {131, 13331};
pair<ll,ll> hsha[maxn], hshb[maxn];
int mch[maxn], vis[maxn];
bitset<1500> eq[maxn], lt[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> b[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        ll h1 = 0, h2 = 0;
        for(int j = 1; j <= m; ++j) {
            h1 = (h1 * p[0] + a[i][j]) % mod[0];
            h2 = (h2 * p[1] + a[i][j]) % mod[1];
        }
        hsha[i] = {h1, h2};
    }
    for(int i = 1; i <= n; ++i) {
        ll h1 = 0, h2 = 0;
        for(int j = 1; j <= m; ++j) {
            h1 = (h1 * p[0] + b[i][j]) % mod[0];
            h2 = (h2 * p[1] + b[i][j]) % mod[1];
        }
        hshb[i] = {h1, h2};
    }
    for(int i = 1; i <= n; ++i) {
        int found = 0;
        for(int j = 1; j <= n; ++j) {
            if(mch[j]) continue;
            if(hsha[i] == hshb[j]) {
                mch[j] = i;
                found = 1;
                break;
            }
        }
        if(!found) return cout << -1 << endl, 0;
    }
    for(int i = 1; i <= n; ++i) b[i][m + 1] = mch[i];
    for(int i = 1; i <= m + 1; ++i) {
        for(int j = 1; j < n; ++j) {
            if(b[j][i] == b[j+1][i]) eq[i][j-1] = 1;
            if(b[j][i] > b[j+1][i]) lt[i][j-1] = 1;
        }
    }
    bitset<1500> cur; cur.set();
    vector<int> ans;
    while(cur.any()) {
        int found = 0;
        for(int i = 1; i <= m + 1; ++i) {
            if(vis[i] || (lt[i] & cur).any()) continue;
            cur &= eq[i];
            ans.push_back(i);
            vis[i] = 1;
            found = 1;
        }
        if(!found) break;
        if(ans.back() == m + 1) break;
    }
    if(cur.any()) cout << -1 << endl;
    else {
        if(ans.size() && ans.back() == m + 1) ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(int i : ans) cout << i << " "; cout << endl;
    }
}