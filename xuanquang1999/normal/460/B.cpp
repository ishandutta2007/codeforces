using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(ll i = r; i >= l; --i)
#define fto(i, l, r) for(ll i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

ll a, b, c;
vector<ll> ans;

ll _pow(ll x, ll n) {
    ll res = 1;
    fto(i, 1, n) res*=x;
    return res;
}

ll sumDigit(ll x) {
    ll res = 0;
    while (x > 0) {
        res+=x%10;
        x/=10;
    }
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> a >> b >> c;

    fto(s, 0, 99) {
        ll x = b*_pow(s, a)+c;
        if (x > 0 && x < 1000000000 && sumDigit(x) == s) ans.pb(x);
//        debug(s);
//        debug(x);
//        debug(sumDigit(x));
//        debug(_pow(s, a));
    }

    ll n = ans.size();
    cout << n << endl;
    fto(i, 0, n-1) cout << ans[i] << " ";

    return 0;
}