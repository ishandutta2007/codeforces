#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5e4 + 5, M = 3e2 + 5;
const ll infll = (ll)1e18 + 7;

int n, m, d;
int a[M], b[M], t[M];

ll dp[N], tdp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> d;
    ForE(i, 1, m){
        cin >> a[i] >> b[i] >> t[i];
    }

    ForE(i, 1, m){
        ForE(j, 1, n){
            tdp[j] = dp[j];
        }
        ForE(j, 1, n){
            dp[j] = -infll;
        }
        int td = min((ll)n, (ll)(t[i] - t[i - 1]) * d);
        deque <int> dq;
        ForE(j, 1, n){
            while (!dq.empty() and tdp[dq.back()] < tdp[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if (j - td - 1 >= 1 and !dq.empty() and dq.front() == j - td - 1){
                dq.pop_front();
            }
            dp[j] = max(dp[j], dq.empty() ? -infll : tdp[dq.front()] + b[i] - abs(a[i] - j));
        }
        dq.clear();
        FordE(j, n, 1){
            while (!dq.empty() and tdp[dq.back()] < tdp[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if (j + td + 1 <= n and !dq.empty() and dq.front() == j + td + 1){
                dq.pop_front();
            }
            dp[j] = max(dp[j], dq.empty() ? -infll : tdp[dq.front()] + b[i] - abs(a[i] - j));
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
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