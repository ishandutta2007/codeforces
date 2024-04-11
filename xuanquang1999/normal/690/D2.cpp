//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 700005
#define MOD 1000003

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll Pow(ll x, ll n) {
    if (n == 0) return 1;
    if (n%2 == 1) return (x*Pow(x, n-1))%MOD;
    ll p = Pow(x, n/2);
    return (p*p)%MOD;
}

ll n, C, fact[maxN];

ll Comb(ll k, ll n) {

    ll t = Pow((fact[k]*fact[n-k])%MOD, MOD-2);

    //debug(t);
    return (fact[n]*t)%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> C;

    fact[0] = 1;
    fto(i, 1, n+C-1) fact[i] = (fact[i-1]*i)%MOD;
    //debug(Comb(1, 5));
    ll ans = 0;
    fto(k, 1, C) {
        ans = (ans+Comb(n-1, n+k-1))%MOD;
    }
    cout << ans;








    return 0;
}
/*
C(C, n+C-1) = (n+C-1)!/(n!*(C-1))
*/