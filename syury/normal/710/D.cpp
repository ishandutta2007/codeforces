//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

ll a1, b1, a2, b2;

void bezout(ll a, ll b, ll & x, ll & y){
    if(!a){
        x = 0; y = 1;
        return;
    }
    ll x1, y1;
    bezout(b%a, a, x1, y1);
    y = x1;
    x = y1 - (b/a)*x1;
}

ll crt(ll x1, ll m1, ll x2, ll m2){
    ll g = __gcd(m1, m2);
    if(x1%g != x2%g)
        return -1;
    ll x, y;
    bezout(m1, m2, x, y);
    ll mod = m1/g*m2;
    __int128 ans = __int128(x2) * x %mod * (m1/g) + __int128(x1) * y %mod * (m2/g);
    return (ans%mod + mod)%mod;
}

inline ll maxle(ll b, ll a){
    ll x = a/b;
    assert(b * (x + 1) > a);
    if(b*x > a)
        --x;
    return x;
}

inline ll minge(ll b, ll a){
    ll x = maxle(b, a);
    if(x * b == a)
        return x;
    else
        return 1 + x;
}

ll solve(ll x){
    ll rem1 = (b1%a1 + a1)%a1;
    ll rem2 = (b2%a2 + a2)%a2;
    ll common = crt(rem1, a1, rem2, a2);
    //cout << rem1 << ' ' << rem2 << ' ' << common << endl;
    if(common == -1)
        return 0;
    ll mod = a1/__gcd(a1, a2) * a2;
    ll mx = max(minge(mod, b1 - common), minge(mod, b2 - common));
    //cout << common + mod * mx << endl;
    ll mi = maxle(mod, x - common);
    //cout << mod - common << endl;
    //cout << common + mod * mi << ' ' << x << endl;
    //cout << mx << ' ' << mi << endl;
    if(mx <= mi)
        return mi - mx + 1;
    else
        return 0;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a1 >> b1 >> a2 >> b2;
    ll L, R;
    cin >> L >> R;
    cout << solve(R) - solve(L - 1) << endl;
    return 0;
}