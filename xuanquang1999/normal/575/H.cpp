using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1000005
#define mod 1000000007
ll n, ans, fact[maxN*2];

ll powmod(ll x, int n) {
    if (n == 0) return 1;
    else {
        ll p = powmod(x, n>>1);
        if (n&1) return ((p*p)%mod * x)%mod;
        return (p*p)%mod;
    }
}

ll C(int k, int n) {
    return (fact[n]*powmod((fact[k]*fact[n-k])%mod, mod-2))%mod;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;

    fact[0] = 1;
    fto(i, 1, 2*maxN-1) fact[i] = (fact[i-1]*i)%mod;
    //fto(i, 0, 2*n) debug(fact[i]);

    //printf("Here\n");

    ans = 1;
    fto(i, 1, n) ans = (ans+C(i+1, 2*i)*2+C(i, 2*i))%mod;

    cout << ans;
    //debug(C(3, 5));
    //debug(powmod(2, 5));

    return 0;
}