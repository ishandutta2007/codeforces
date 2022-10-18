#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

int valmsk[48], arrnmsk[48][10];
ll dp[19][2][48][2520];

vi vdig;

ll caldp(int pos, bool reach, int msk, int rem){
    if (pos == isz(vdig)){
        return rem % valmsk[msk] ? 0 : 1;
    }
    if (dp[pos][reach][msk][rem] != -1){
        return dp[pos][reach][msk][rem];
    }
    dp[pos][reach][msk][rem] = 0;
    int lim = reach ? vdig[pos] : 9;
    ForE(dig, 0, lim){
        int npos = pos + 1;
        bool nreach = reach & (dig == lim);
        int nmsk = arrnmsk[msk][dig];
        int nrem = (rem * 10 + dig) % 2520;
        dp[pos][reach][msk][rem] += caldp(npos, nreach, nmsk, nrem);
    }
    return dp[pos][reach][msk][rem];
}

ll cal(ll n){
    if (!n){
        return 1;
    }
    vdig.clear();
    while (n){
        vdig.emplace_back(n % 10);
        n /= 10;
    }
    reverse(bend(vdig));
    memset(dp, -1, sizeof(dp));
    return caldp(0, 1, 0, 0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
For(msk, 0, 48){
    int exp2 = (msk / 1) % 4, exp3 = (msk / 4) % 3, exp5 = (msk / 12) % 2, exp7 = (msk / 24) % 2;
    valmsk[msk] = 1;
    ForE(i, 1, exp2){
        valmsk[msk] *= 2;
    }
    ForE(i, 1, exp3){
        valmsk[msk] *= 3;
    }
    ForE(i, 1, exp5){
        valmsk[msk] *= 5;
    }
    ForE(i, 1, exp7){
        valmsk[msk] *= 7;
    }
    ForE(dig, 0, 9){
        arrnmsk[msk][dig] = msk;
        if (dig == 2 and exp2 < 1){
            arrnmsk[msk][dig] -= exp2 * 1;
            arrnmsk[msk][dig] += 1 * 1;
        }
        if (dig == 3 and exp3 < 1){
            arrnmsk[msk][dig] -= exp3 * 4;
            arrnmsk[msk][dig] += 1 * 4;
        }
        if (dig == 4 and exp2 < 2){
            arrnmsk[msk][dig] -= exp2 * 1;
            arrnmsk[msk][dig] += 2 * 1;
        }
        if (dig == 5 and exp5 < 1){
            arrnmsk[msk][dig] -= exp5 * 12;
            arrnmsk[msk][dig] += 1 * 12;
        }
        if (dig == 6 and (exp2 < 1 or exp3 < 1)){
            arrnmsk[msk][dig] -= exp2 * 1;
            arrnmsk[msk][dig] += max(exp2, 1) * 1;
            arrnmsk[msk][dig] -= exp3 * 4;
            arrnmsk[msk][dig] += max(exp3, 1) * 4;
        }
        if (dig == 7 and exp7 < 1){
            arrnmsk[msk][dig] -= exp7 * 24;
            arrnmsk[msk][dig] += 1 * 24;
        }
        if (dig == 8 and exp2 < 3){
            arrnmsk[msk][dig] -= exp2 * 1;
            arrnmsk[msk][dig] += 3 * 1;
        }
        if (dig == 9 and exp3 < 2){
            arrnmsk[msk][dig] -= exp3 * 4;
            arrnmsk[msk][dig] += 2 * 4;
        }
    }
}
int tests; cin >> tests; ForE(test, 1, tests){
    ll l, r; cin >> l >> r;
    ll ans = cal(r);
    ans -= cal(l - 1);
    cout << ans << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/