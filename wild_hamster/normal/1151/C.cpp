#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r;
map<ll, ll> f;
ll a[505][505];

ll get(ll p) {
    if (p == 0) {
        return 0;
    }
    ll pars[2];
    pars[0] = pars[1] = 0;
    ll cur_par = 1;
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < 61; i++) {
        ll need = min((1LL<<i), p - cur);
        ll lt = pars[cur_par], rt = pars[cur_par] + need - 1;
        ll p1 = lt * 2 + rt * 2 + (2 - cur_par) * 2, p2 = rt - lt + 1;
        if (p1 % 2) {
            p2 /= 2;
        } else {
            p1 /= 2;
        }
        ll sum = (p1 % MOD) * (p2 % MOD) % MOD;
        ans = (ans + sum) % MOD;
        if (p - cur <= 1LL << i) {
            return ans;
        }
        pars[cur_par] += (1LL<<i);
        cur_par ^= 1;
        cur += 1LL << i;
    }
}
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> l >> r;
    cout << (get(r) - get(l-1) + MOD) % MOD;
    return 0;
}