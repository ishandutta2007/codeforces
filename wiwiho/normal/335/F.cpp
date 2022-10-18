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
    if(pvaspace) b << " "; \
    pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define SZ(a) int(a.size())

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

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<>());

    std::priority_queue<ll, vector<ll>, greater<>> pq;
    for(int id = 1; id <= n; ){
        int big = id - 1;
        int x = a[id];
        int cnt = 0;
        for(; id <= n && a[id] == x; id++) cnt++;
        
        int free = min(cnt, big - 2 * SZ(pq));
        //cerr << "test " << x << " " << cnt << " " << free << "\n";
        vector<ll> upd;
        for(int i = 0; i < free; i++){
            upd.eb(x);
        }

        for(int i = 0; i < (cnt - free) / 2; i++){
            if(pq.empty() || pq.top() >= x * 2) break;
            ll mn = pq.top();
            pq.pop();
            if(mn <= x){
                upd.eb(x);
                upd.eb(x);
            }
            else if(mn < 2 * x){
                upd.eb(mn);
                upd.eb(2 * x - mn);
            }
        }
        if((cnt - free) % 2 && !pq.empty() && pq.top() < x){
            pq.pop();
            upd.eb(x);
        }

        for(ll i : upd){
            //cerr << "push " << i << "\n";
            pq.push(i);
        }
    }

    ll ans = accumulate(iter(a), 0LL);
    //cerr << ans << "\n";
    while(!pq.empty()){
        ll mn = pq.top();
        //cerr << "ok " << mn << "\n";
        ans -= mn;
        pq.pop();
    }
    cout << ans << "\n";

    return 0;
}