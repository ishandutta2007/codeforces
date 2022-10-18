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

const ll MOD = 998244353;
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

struct info{
    ll b, s, id, tc;
    bool operator<(const info t) const {
        return b + s < t.b + t.s;
    }
    bool operator<(int v) const {
        return b + s < v;
    }
};

const int SZ = 30;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii> tmp(n);
    for(int i = 0; i < n; i++) cin >> tmp[i].F >> tmp[i].S;
    sort(iter(tmp), [&](pii a, pii b){ return a.S == b.S ? a.F < b.F : a.S > b.S; });

    vector<ll> a(n + 1);
    vector<vector<ll>> sum(SZ, vector<ll>(n + 1));
    vector<vector<ll>> cnt(SZ, vector<ll>(n + 1));
    for(int i = 1; i <= n; i++){
        a[i] = tmp[i - 1].F;
        for(int j = __lg(a[i]) + 1; j < SZ; j++) sum[j][i] = a[i], cnt[j][i]++;
    }
    //printv(a, cerr);

    for(int i = 0; i < SZ; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] += sum[i][j - 1];
            cnt[i][j] += cnt[i][j - 1];
        }
        //cerr << "sum " << i << "  ";
        //printv(sum[i], cerr);
    }

    vector<vector<vector<pii>>> qry(SZ, vector<vector<pii>>(n + 1));
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int b;
        cin >> b;
        qry[__lg(b)][0].eb(mp(b, i));
    }
        
    vector<int> ans(k);
    for(int i = SZ - 1; i >= 0; i--){
        multiset<info, less<>> pq;

        for(pii j : qry[i][0]){
            pq.insert(info({j.F, 0, j.S, 0}));
        }
        
        for(int j = 1; j <= n; j++){
            auto it = pq.lower_bound(sum[i][j - 1] + a[j]);
            while(it != pq.end() && (it->b + it->s < (1LL << i) + sum[i][j - 1] + a[j])){
                info now = *it;
                it = pq.erase(it);
                ll c = sum[i][j - 1] + a[j] - now.s;
                //cerr << "test " << i << " " << j << "  " << now.b << " " << now.s << " " << now.id << " " << now.tc << "  " << c << " " << ans[now.id] << "\n";
                now.b -= c;
                ans[now.id] += cnt[i][j - 1] - now.tc + 1;
                if(now.b) qry[__lg(now.b)][j].eb(mp(now.b, now.id));
            }
            for(pii t : qry[i][j]){
                pq.insert(info({t.F, sum[i][j], t.S, cnt[i][j]}));
            }
        }
        while(!pq.empty()){
            info now = *pq.begin();
            pq.erase(pq.begin());
            ans[now.id] += cnt[i][n] - now.tc;
        }
    }

    for(int i = 0; i < k; i++) cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}