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
#include <fstream>
 
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
 
typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll b[1000500], a[1000500], d[1005000];
ll ii;
 
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}
 
ll get(ll x) {
    if (b[x] != ii) {
        return 0;
    }
    return a[x];
}
vector<ll> used;
 
void try_shit(ll id) {
    ll sum = 1;
    ll tot_sum = 0;
    ll sid = id;
    while (sum <= 1000000 + 5 && id > 0) {
        id--;
        sum *= m;
        if (get(id) >= sum) {
            a[id] -= sum;
            for (int j = id+1; j <= sid; j++) {
                a[j] = 0;
            }
            return;
        } else {
            sum -= get(id);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    for (ii = 1; ii <= t; ii++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        if (m == 1) {
            cout << n%2 << "\n";
            continue;
        }
        used.clear();
        for (int i = 0; i < n; i++) {
            if (b[d[i]] != ii) {
                b[d[i]] = ii;
                a[d[i]] = 1;
                used.push_back(d[i]);
            } else {
                a[d[i]]++;
            }
        }
        sort(used.begin(), used.end());
        ll sz = used.size();
        ll ans = 0;
        for (int pos = sz - 1; pos >= 0; pos--) {
            ll id = used[pos];
            a[id] %= 2;
            if (a[id] == 0) {
                continue;
            }
            if (a[id] == 1) {
                try_shit(id);
            }
            if (a[id] == 1) {
                ans += binpow(m, id);
                for (int j = 0; j < pos; j++) {
                    ll curid = used[j];
                    ans -= binpow(m, curid) * a[curid];
                }
                break;
            }
        }
        ans = (ans + 1LL * MOD * MOD) % MOD;
        cout << ans << "\n";
    }
 
    return 0;
}