//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

inline int sgn(int x){
    return x < 0 ? -1 : int(!!x);
}

void fail(){
    cout << -1;
    exit(0);
}

ll gcdex(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll g = gcdex(b%a, a, x1, y1);
    y = x1;
    x = y1 - (b/a)*x1;
    return g;
}

pair<ll, ll> dioph(ll a, ll b, ll c){
    ll g = __gcd(llabs(a), llabs(b));
    if(c%g)
        fail();
    a /= g; b /= g; c /= g;
    ll x, y;
    gcdex(llabs(a), llabs(b), x, y);
    if(a < 0)x *= -1;
    if(b < 0)y *= -1;
    x *= c; y *= c;
    return {x, y};
}


__int128 abs(__int128 x){
    return x < 0 ? -x : x;
}


__int128 le(__int128, __int128);

__int128 ge(__int128 Q, __int128 P){
    if(Q < 0)
        return le(-Q, -P);
    if(P < 0){
        return -(abs(P)/Q);
    }
    else{
        return P/Q + int(P%Q > 0);
    }
}

__int128 le(__int128 Q, __int128 P){
    if(Q < 0)
        return ge(-Q, -P);
    if(P < 0){
        return -(abs(P)/Q) - int(abs(P)%Q > 0);
    }
    else{
        return P/Q;
    }
}

void solve(){
    ll n, m, x, y, dx, dy;
    cin >> n >> m >> x >> y >> dx >> dy;
    if(min(abs(dx), abs(dy)) == 0){
        if(dx == -1){
            if(y == 0 || y == m)
                cout << 0 << ' ' << y << endl;
            else fail();
            return;
        }
        if(dx == 1){
            if(y == 0 || y == m)
                cout << n << ' ' << y << endl;
            else fail();
            return;
        }
        if(dy == -1){
            if(x == 0 || x == n)
                cout << x << ' ' << 0 << endl;
            else fail();
            return;
        }
        if(dy == 1){
            if(x == 0 || x == n)
                cout << x << ' ' << m << endl;
            else fail();
            return;
        }
        assert(false);
    }
    __int128 fin_x, fin_y;
    ll G = __gcd(n, m);
    if(sgn(dx) == sgn(dy)){
        ll x0, y0;
        tie(x0, y0) = dioph(n, -m, x - y);
        __int128 k2 = dx > 0 ? ge(-m/G * __int128(n), x - x0 * __int128(n)) : le(-m/G * __int128(n), x - x0 * __int128(n));
        fin_x = (x0 + k2 * (-m/G));
        fin_y = (y0 - k2 * (n/G));
    }
    else{
        ll x0, y0;
        tie(x0, y0) = dioph(n, m, x + y);
        __int128 k2 = dx > 0 ? ge(m/G * __int128(n), x - x0 * __int128(n)) : le(m/G * __int128(n), x - x0 * __int128(n));
        fin_x = (x0 + k2 * (m/G));
        fin_y = (y0 - k2 * (n/G));
    }
    int row = abs(fin_y%2);
    int col = abs(fin_x%2);
    if(row){
        if(col)
            cout << n << ' ' << m << endl;
        else
            cout << 0 << ' ' << m << endl;
    }else{
        if(col)
            cout << n << ' ' << 0 << endl;
        else
            cout << 0 << ' ' << 0 << endl;
    }
}

signed main(){
//    freopen("areas.in", "r", stdin);
//    freopen("areas.out", "w", stdout);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}