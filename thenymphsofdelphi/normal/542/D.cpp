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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

mt19937_64 rando(chrono::steady_clock::now().time_since_epoch().count());
ll randt(ll l, ll r){ return rando() % (r - l + 1) + l; }

const int N = 1e6 + 5;

ll n;
ll ctrd, d[N];
int s;

ll dp1[N], dp2[N];
bool ckprime[N];
int ctrprime, prime[N];

void cal(ll x){
    if (n % x){
        return;
    }
    int idx = ctrd;
    FordE(i, ctrd, 1){
        if (d[i] % x){
            continue;
        }
        while (d[idx] * x != d[i]){
            idx--;
        }
        dp2[i] += dp1[idx];
    }
}

bool isprime(ll x){
    ForE(i, 1, ctrprime){
        if ((ll)prime[i] * prime[i] > x){
            return 1;
        }
        if (!(x % prime[i])){
            return 0;
        }
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; (ll)i * i <= n; i++){
        s = i;
        if (n % i){
            continue;
        }
        d[++ctrd] = i;
        d[++ctrd] = n / i;
        if (d[ctrd] == d[ctrd - 1]){
            ctrd--;
        }
    }
    sort(d + 1, d + 1 + ctrd);
    dp1[1] = dp2[1] = 1;
    ForE(i, 2, s){
        if (!ckprime[i]){
            ckprime[i] = 1;
            prime[++ctrprime] = i;
            for (ll j = i; j < n; j *= i){
                cal(j + 1);
            }
            memcpy(dp1, dp2, (ctrd + 1) * sizeof(ll));
        }
        for (int j = 1; j <= ctrprime && prime[j] <= i && i * prime[j] <= s; j++){
            ckprime[prime[j] * i] = 1;
        }
    }
    FordE(i, ctrd, 1){
        if (d[i] - 1 <= s){
            break;
        }
        if (isprime(d[i] - 1)){
            cal(d[i]);
            memcpy(dp1, dp2, (ctrd + 1) * sizeof(ll));
        }
    }
    cout << dp1[ctrd] << endl;
}