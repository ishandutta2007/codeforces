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

const int N = 3e5 + 5;

int n, m;
int p[N], invp[N];

int cnt[N];

int q[N], invq[N];

bool cal(int k){
    ForE(i, 1, k){
        q[i] = i - k + n; invq[q[i]] = i;
    }
    ForE(i, k + 1, n){
        q[i] = i - k; invq[q[i]] = i;
    }
    int cnt = 0;
    ForE(i, 1, n){
        if (q[i] == p[i]){
            continue;
        }
        cnt++;
        int x = invq[p[i]];
        invq[q[i]] = x;
        invq[q[x]] = i;
        swap(q[i], q[x]);
    }
    return cnt <= m;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; ForE(test, 1, tests){
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> p[i]; invp[p[i]] = i;
    }

    For(k, 0, n){
        cnt[k] = 0;
    }
    ForE(i, 1, n){
        if (i < p[i]){
            cnt[n - p[i] + i]++;
        }
        else{
            cnt[i - p[i]]++;
        }
    }
    vi vans;
    For(k, 0, n){
        if (cnt[k] >= n - 2 * m and cal(k)){
            vans.emplace_back(k);
        }
    }
    cout << isz(vans) << ' ';
    Fora(&v, vans){
        cout << v << ' ';
    } cout << endl;
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