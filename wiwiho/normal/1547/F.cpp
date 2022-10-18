
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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

vector<int> prime, lpd;

void sieve(int n){
    lpd.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(lpd[i] == 1){
            lpd[i] = i;
            prime.eb(i);
        }
        for(int j : prime){
            if((ll)i * j > n) break;
            lpd[i * j] = j;
            if(j == lpd[i]) break;
        }
    }
}

void solve(){

    int n;
    cin >> n;

    map<int, vector<pii>> pos;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        while(a > 1){
            int d = lpd[a];
            int cnt = 0;
            while(a % d == 0){
                a /= d;
                cnt++;
            }
            pos[d].eb(mp(i, cnt));
        }
    }

    int ans = 0;
    for(auto& ii : pos){
        auto& i = ii.S;
//        cerr << "test ";
//        printv(i, cerr);
        int mn = 0;
        if(i.size() == n){
            mn = MAX;
            for(auto j : i) mn = min(mn, j.S);
        }
//        cerr << mn << "\n";
        vector<int> tmp;
        for(auto j : i){
            if(j.S != mn) tmp.eb(j.F);
        }
        int tsz = tmp.size();
        for(int j = 0; j < tsz; j++) tmp.eb(tmp[j] + n);
//        printv(tmp, cerr);
        int lst = -87;
        int now = 0;
        for(int j : tmp){
            if(lst != j - 1) now = 0;
            now++;
            ans = max(ans, now);
            lst = j;
        }
    }

    cout << ans << "\n";
}

int main(){
    StarBurstStream

    sieve(1000000);

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}