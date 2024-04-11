#include <bits/stdc++.h>
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;

pll exgcd(ll a, ll b){
    if(b == 0) return mp(1, 0);
    pll ans = exgcd(b, a % b);
    return mp(ans.S, ans.F - a / b * ans.S);
}

pll calc(ll a, ll b, ll c){
    ll g = __gcd(a, b);
    ll t = c / g;
    pll ans = exgcd(a, b);
    ans.F *= t;
    ans.S *= t;
    return ans;
}

int main(){
    StarBurstStream

    ll n, m, x0, y0, vx, vy;
    cin >> n >> m >> x0 >> y0 >> vx >> vy;

    if(vx == 0){
        if(x0 != 0 && x0 != n) return cout << "-1\n", 0;
        if(vy == -1) cout << x0 << " " << 0 << "\n";
        else cout << x0 << " " << m << "\n";
        return 0;
    }
    if(vy == 0){
        if(y0 != 0 && y0 != m) return cout << "-1\n", 0;
        if(vx == -1) cout << 0 << " " << y0 << "\n";
        else cout << n << " " << y0 << "\n";
        return 0;
    }

    ll tx = vx, ty = vy;
    vx = 1; vy = 1;
    if(tx < 0) x0 = n - x0;
    if(ty < 0) y0 = m - y0;

    if((x0 - y0) % __gcd(n, m)){
        cout << "-1\n";
        return 0;
    }
    ll M = n * m / __gcd(n, m);
    pll ans = calc(n, -m, x0 - y0);
    ll g = __gcd(n, m);
    ll t = (ans.F % (m / g) * n - x0) % M;
    t = (t % M + M) % M;

    ll x = x0 + t, y = y0 + t;
//    cerr << x / n << " " << y / m << "\n";
    if(tx < 0) x = n - x;
    if(ty < 0) y = m - y;
//    cerr << x % n << " " << y % m << "\n";

    x = n * abs(x / n % 2);
    y = m * abs(y / m % 2);
    cout << x << " " << y << "\n";

    return 0;
}