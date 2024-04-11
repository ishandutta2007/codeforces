#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

bool isprime(int x){
    if (x <= 1){
        return 0;
    }
    if (x <= 3){
        return 1;
    }
    if (x % 2 == 0 or x % 3 == 0){
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6){
        if (x % i == 0 or x % (i + 2) == 0){
            return 0;
        }
    }
    return 1;
}

template <class T>
pair <T, T> add(const pair <T, T> &lhs, const pair <T, T> &rhs){
    return make_pair(lhs.fi * rhs.se + rhs.fi * lhs.se, lhs.se * rhs.se);
}

template <class T>
pair <T, T> sub(const pair <T, T> &lhs, const pair <T, T> &rhs){
    return make_pair(lhs.fi * rhs.se - rhs.fi * lhs.se, lhs.se * rhs.se);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    int n; cin >> n;
    int m = n;
    while (!isprime(m)){
        m--;
    }
    int k = n + 1;
    while (!isprime(k)){
        k++;
    }

    pair <__int128_t, __int128_t> ans = make_pair(1, 2);
    ans = sub(ans, make_pair((__int128_t)1, (__int128_t)m));
    ans = add(ans, make_pair((__int128_t)(n - m + 1), (__int128_t)m * k));

    __int128_t g = __gcd(ans.fi, ans.se); ans.fi /= g; ans.se /= g;
    cout << (ll)ans.fi << '/' << (ll)ans.se << endl;
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