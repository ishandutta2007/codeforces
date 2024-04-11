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

const int N = 1e6 + 5;

int n;
int a[N];

ll dp[N];
stack <int> dqmx, dqmn;
multiset <ll> mtsmx, mtsmn; // -a[i] + dp[i - 1], a[i] + dp[i - 1]

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        while (!dqmx.empty() and a[dqmx.top()] >= a[i]){
            mtsmx.erase(mtsmx.find(-a[dqmx.top()] + dp[dqmx.top() - 1]));
            dqmx.pop();
        }
        dqmx.push(i);
        mtsmx.insert(-a[i] + dp[i - 1]);
        dp[i] = max(dp[i], a[i] + (*(--mtsmx.end())));
        while (!dqmn.empty() and a[dqmn.top()] <= a[i]){
            mtsmn.erase(mtsmn.find(a[dqmn.top()] + dp[dqmn.top() - 1]));
            dqmn.pop();
        }
        dqmn.push(i);
        mtsmn.insert(a[i] + dp[i - 1]);
        dp[i] = max(dp[i], -a[i] + (*(--mtsmn.end())));
    }
    cout << dp[n] << endl;
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