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

const int N = 1e5 + 5;

int lpf[N];
vi vprime;

int idxvprime[N];

void sieve(){
    memset(idxvprime, -1, sizeof(idxvprime));
    For(i, 2, N){
        if (lpf[i] == 0){
            lpf[i] = i;
            vprime.emplace_back(i);
            idxvprime[i] = isz(vprime) - 1;
        }
        for (int j = 0; j < isz(vprime) and vprime[j] <= lpf[i] and vprime[j] * i < N; j++){
            lpf[vprime[j] * i] = vprime[j];
        }
    }
    FordE(i, N - 2, 0){
        if (idxvprime[i] == -1){
            idxvprime[i] = idxvprime[i + 1];
        }
    }
}

vi vdig[N];

vi get_dig(int x){
    vi vans;
    while (x){
        vans.emplace_back(x % 10);
        x /= 10;
    }
    reverse(bend(vans));
    return vans;
}

int pw10[6];

int n;
int a[5][5];

int ans;

void backtrack(int i){
    if (i == n){
        ans++;
        return;
    }
    int val = 0;
    For(j, 0, i){
        val = val * 10 + a[i][j];
    }
    For(j, i, n){
        val = val * 10;
    }
    int idx = idxvprime[val];
    if (idx == -1){
        return;
    }
    while (idx < isz(vprime) and vprime[idx] < val + pw10[n - i]){
        For(j, i, n){
            a[i][j] = a[j][i] = (j + isz(vdig[vprime[idx]]) >= n ? vdig[vprime[idx]][isz(vdig[vprime[idx]]) - n + j] : 0);
        }
        backtrack(i + 1);
        idx++;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
sieve();
pw10[0] = 1;
For(i, 1, 6){
    pw10[i] = pw10[i - 1] * 10;
}
For(i, 1, N){
    vdig[i] = get_dig(i);
}
int tests; cin >> tests; while (tests--){
    int p; cin >> p;

    vi vdigp = vdig[p]; n = isz(vdigp);
    memset(a, 0, sizeof(a));
    For(i, 0, n){
        a[0][i] = a[i][0] = vdigp[i];
    }
    ans = 0;
    backtrack(1);
    cout << ans << endl;
}
}