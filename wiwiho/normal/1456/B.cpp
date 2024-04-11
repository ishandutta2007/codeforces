#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> cnt(35);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[__lg(a[i])]++;
    }

    for(int i = 0; i < 35; i++){
        if(cnt[i] >= 3){
            cout << "1\n";
            return 0;
        }
    }

    ll ans = MAX;
    for(int i = 0; i < n; i++){
        ll f = 0;
        for(int j = i; j >= 0; j--){
            ll b = 0;
            f ^= a[j];
            for(int k = i + 1; k < n; k++){
                b ^= a[k];
//                cerr << i << " " << j << " " << k << " " << f << " " << b << "\n";
                if(f > b) ans = min(ans, (ll)(i - j) + (k - i - 1));
            }
        }
    }
    if(ans == MAX) ans = -1;
    cout << ans << "\n";

    return 0;
}