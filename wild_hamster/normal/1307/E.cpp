
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

typedef int ll;
using namespace std;
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[5005];
vector<ll> cows[5005];
ll stl[5005], str[5005];
ll pl[5005], pr[5005];
ll sum_col[5005], sumcow[5005];
ll suml[5005], sumr[5005];
ll pre[100500];
pii cur_ans;
void update(ll x, ll y) {
    if (y == 0) {
        return;
    }
    if (x > cur_ans.X) {
        cur_ans = mp(x, y);
    } else if (x == cur_ans.X) {
        cur_ans.Y += y;
        if (cur_ans.Y >= MOD) {
            cur_ans.Y -= MOD;
        }
    }
}

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = 1LL * tmp * tmp % MOD;
    if (y % 2) {
        return 1LL * x * tmp % MOD;
    }
    return tmp;
}


ll inv(pii v) {
    ll x = v.X;
    ll y = v.Y;
    ll ans = 1;
    if (pre[x] == 0) {
        pre[x] = binpow(x, MOD - 2);
    }
    if (pre[y] == 0) {
        pre[y] = binpow(y, MOD - 2);
    }
    return 1LL * pre[x] * pre[y] % MOD;
}

ll get_sum(ll x, ll y) {
    if (x + y == 0) {
        return 0;
    }
    if (x == 0 || y == 0) {
        return 1;
    }
    if (x == 1 && y == 1) {
        return 1;
    }
    return 2;
}

pii get_probs(ll x, ll y) {
    if (x > y) {
        swap(x, y);
    }
    if (x + y == 0) {
        return mp(1, 1);
    }
    if (x == 0) {
        return mp(y, 1);
    }
    if (x == 1 && y == 1) {
        return mp(2, 1);
    }
    return mp(x, y - 1);
}

ll pp(pii x) {
    return x.X * x.Y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_col[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cows[x].push_back(y);
        if (y <= sum_col[x]) {
            sumcow[x]++;
        }
    }
    ll ans = 1;
    ll pshe = 0;
    for (int i = 1; i <= n; i++) {
        if (sumcow[i] > 0) {
            ans = 1LL * ans * sumcow[i] % MOD;
            pshe++;
        }
    }

    update(pshe, ans * 2 % MOD);

    if (pshe == 0) {
        cout << "0 1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        sort(cows[i].begin(), cows[i].end());
    }

    ll suml = 0;
    ll vars = 1;
    for (int i = 0; i < n; i++) {
        ll cownum = a[i];
        stl[cownum]++;
        pii fixed = mp(0, 0);
        if (pl[cownum] < cows[cownum].size() && cows[cownum][pl[cownum]] == stl[cownum]) {
            fixed = mp(cownum, stl[cownum]);
            pl[cownum]++;
            if (pl[cownum] == 1) {
                suml++;
            }
            vars = 1LL * vars * inv(get_probs(0, pl[cownum] - 1)) % MOD;
            vars = 1LL * vars * pp(get_probs(0, pl[cownum])) % MOD;
        }
        ll cur_vars = vars;
        ll cur_sum = suml;
        for (int j = 1; j <= n; j++) {
            pr[j] = 0;
            str[j] = 0;
        }
        if (fixed != mp(0, 0)) {
            //cout << fixed.X << " " << fixed.Y << "\n";
            for (int j = n - 1; j > i; j--) {
                ll rnum = a[j];
                str[rnum]++;
                if (pr[rnum] < cows[rnum].size() && cows[rnum][pr[rnum]] == str[rnum]) {
                    pr[rnum]++;
                    cur_sum -= get_sum(pr[rnum] - 1, pl[rnum]);
                    cur_sum += get_sum(pr[rnum], pl[rnum]);
                    cur_vars = 1LL * cur_vars * inv(get_probs(pl[rnum], pr[rnum] - 1)) % MOD;
                    cur_vars = 1LL * cur_vars * pp(get_probs(pl[rnum], pr[rnum])) % MOD;
                    if (mp(rnum, str[rnum]) != fixed) {
                        ll cur_pshum = cur_sum;
                        ll cur_pshars = cur_vars;
                        if (cur_pshum >= cur_ans.X) {
                            if (rnum == cownum) {
                                cur_pshars = 1LL * cur_pshars * inv(get_probs(pl[rnum], pr[rnum])) % MOD;
                            } else {
                                cur_pshars = 1LL * cur_pshars * inv(get_probs(pl[rnum], pr[rnum])) % MOD;
                                cur_pshars = 1LL * cur_pshars * inv(get_probs(pl[cownum], pr[cownum])) % MOD;
                                cur_pshars = 1LL * cur_pshars * max(1, pl[rnum] - (pr[rnum] <= pl[rnum])) % MOD;
                                cur_pshars = 1LL * cur_pshars * max(1, pr[cownum] - (pl[cownum] <= pr[cownum])) % MOD;
                            }
                            update(cur_pshum, cur_pshars);
                        }
                    }
                }
            }
        }
    }
    if (cur_ans.X == 0) {
        cout << "0 1\n";
        return 0;
    } else {
        cout << cur_ans.X << " " << cur_ans.Y << "\n";
    }
    return 0;
}