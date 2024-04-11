#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define eb emplace_back
#define ef emplace_front
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define F first
#define S second
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define printv(a, b) { \
    for(auto pv : a) b << pv << " "; \
    b << "\n"; \
}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a/ b;
}

void trans(vector<ll>& a, int n){
    for(int i = n; i >= 2; i--){
        a[i] = a[i] - a[i - 2] - a[i - 1];
        topos(a[i]);
    }
}

int main(){
    StarBurstStream;
    //freopen("test.txt", "w", stderr);
    cerr.tie(0);

    int n, q;
    cin >> n >> q >> MOD;
    vector<ll> fib(n + 10);
    fib[1] = 1 % MOD;
    for(int i = 2; i < n + 10; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    vector<ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    trans(a, n); trans(b, n);
    //printv(a, cerr);
    //printv(b, cerr);

    int ok = 0;
    for(int i = 1; i <= n; i++) if(a[i] == b[i]) ok++;

    auto upd = [&](char ty, int i, int v){
        if(i > n) return;
        if(a[i] == b[i]) ok--;
        if(ty == 'A') a[i] += v;
        else b[i] += v;
        topos(a[i]);
        topos(b[i]);
        if(a[i] == b[i]) ok++;
    };

    while(q--){
        char ty;
        cin >> ty;
        int l, r;
        cin >> l >> r;
        
        int len = r - l + 1;
        
        upd(ty, l, 1);
        upd(ty, r + 1, -fib[len + 1]);
        upd(ty, r + 2, -fib[len]);

        /*cerr << "test " << ty << " " << l << " " << r << "\n";
        printv(a, cerr);
        printv(b, cerr);*/

        if(ok == n) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}