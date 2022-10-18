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

const ll MOD = 1000000007;
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

void solve(){
    int n;
    ll x, y;
    cin >> n >> x >> y;

    int odd = 0;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        if(a % 2) odd++;
    }

    if(odd % 2 == 0){
        if(x % 2 == y % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else{
        if(x % 2 != y % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}

int main(){
    StarBurstStream;

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}