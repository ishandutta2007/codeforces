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

int dis(int a, int b){
    int ans = 0;
    while(a > 0 && b > 0){
        if(a % 10 != b % 10) ans++;
        a /= 10;
        b /= 10;
    }
    if(a != 0 || b != 0) return -1;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int ans = MAX, ansp = -1;
    for(int i = 7; i <= 999; i += 7){
        int tmp = dis(i, n);
        if(tmp != -1 && tmp < ans){
            ans = tmp; ansp = i;
        }
    }
    cout << ansp << "\n";
}

int main(){
    StarBurstStream;

    int T;
    cin >> T;
    while(T--) solve();


    return 0;
}