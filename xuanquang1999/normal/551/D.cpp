using namespace std;
#include <bits/stdc++.h>
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
#define maxN 100005
ll n, k, l, m, c0, c1;
ll e2[64];
char s[100];
map<ll, ll> f;

ll Fib(ll n) {
    if (f.find(n) != f.end()) return f[n];
    ll k = n/2, s;
    if (n%2 == 0) s = (Fib(k)*Fib(k) + Fib(k-1)*Fib(k-1))%m;
    else s = ((Fib(k+1)+Fib(k-1)) * Fib(k))%m;
    f[n] = s;
    return s;
}

ll powm(ll x, ll n) {
    if (n == 0) return (ll)1;
    ll p = powm(x, n/2);
    if (n%2 == 0) return (p*p)%m;
    else return ((p*p)%m*x)%m;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k >> l >> m;
    e2[0] = 1;
    fto(i, 1, 60) e2[i] = e2[i-1]*2;

    if (l <= 60 && k >= e2[l]) printf("0");
    else {
        fdto(i, min((ll)60, l-1), 0) {
            ll x = k/e2[i];
            k-=x*e2[i];
            s[i] = x;
        }

        f[0] = 1;
        f[1] = 1;
        c0 = Fib(n+1);
        c1 = (powm(2, n)+m-c0)%m;

        ll ans = (ll)1%m;
        fto(i, 0, l-1) {
            if (s[i] == 0) ans=(ans*c0)%m;
            else ans=(ans*c1)%m;
        }
        cout << ans << endl;
    }


    return 0;
}