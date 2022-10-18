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
    cin >> n;
        
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int lst = n;
    while(lst > 1 && a[lst - 1] <= a[lst]) lst--;
    if(lst == n){
        cout << "-1\n";
        return;
    }
    
    if(lst == 1){
        cout << "0\n";
        return;
    }

    if(a[lst] - a[n] > a[lst]){
        cout << "-1\n";
        return;
    }

    cout << lst - 1 << "\n";
    for(int i = 1; i < lst; i++){
        cout << i << " " << lst << " " << n << "\n";
    }
}

int main(){
    StarBurstStream;

    int T;
    cin >> T;
    while(T--){
        solve();
    }


    return 0;
}