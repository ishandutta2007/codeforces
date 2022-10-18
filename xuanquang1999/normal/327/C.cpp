using namespace std;
#include <bits/stdc++.h>
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
#define maxN 100005
const ll mod = 1000000007;

char s[maxN];
ll n, k, ans, a, b, c, d;

ll powmod(ll x, ll n) {
    if (n == 0) return 1;
    else {
        ll p = powmod(x, n/2);
        if (n%2 == 0) return ((p*p)%mod);
        else return (((p*p)%mod * x)%mod);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", s);
    n = strlen(s);
    cin >> k;

    fto(i, 0, n-1)
        if (s[i] == '0' || s[i] == '5') a = (a+powmod(2, i))%mod;

    b = powmod(2, n);
    c = (powmod(b, k)+mod-1)%mod;
    d = (b-1+mod)%mod;

    cout << ((a*c)%mod * powmod(d, mod-2))%mod;

    return 0;
}