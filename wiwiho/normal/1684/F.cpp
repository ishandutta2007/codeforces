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

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<pii> seg(m + 1);
    for(int i = 1; i <= m; i++) cin >> seg[i].F >> seg[i].S;

    int l = n + 1, r = 0;

    {
        vector<vector<int>> ev(n + 2);
        for(int i = 1; i <= m; i++){
            ev[seg[i].F].eb(seg[i].F);
            ev[seg[i].S + 1].eb(-seg[i].F);
        }
        multiset<int> st;
        map<int, int> lst;
        for(int i = 1; i <= n; i++){
            for(int j : ev[i]){
                if(j > 0) st.insert(j);
                else st.erase(st.find(-j));
            }
            if(lst.find(a[i]) != lst.end()){
                int t = lst[a[i]];
                if(!st.empty() && t >= *st.begin()) l = min(l, i);
            }
            lst[a[i]] = i;
        }
    }
    {
        vector<vector<int>> ev(n + 1);
        for(int i = 1; i <= m; i++){
            ev[seg[i].F - 1].eb(-seg[i].S);
            ev[seg[i].S].eb(seg[i].S);
        }
        multiset<int> st;
        map<int, int> lst;
        for(int i = n; i >= 1; i--){
            for(int j : ev[i]){
                if(j > 0) st.insert(j);
                else st.erase(st.find(-j));
            }
            if(lst.find(a[i]) != lst.end()){
                int t = lst[a[i]];
                if(!st.empty() && t <= *st.rbegin()) r = max(r, i);
            }
            lst[a[i]] = i;
        }
    }

    vector<pii> owo;
    {
        vector<vector<int>> ev(n + 2);
        for(int i = 1; i <= m; i++){
            ev[seg[i].F].eb(seg[i].F);
            ev[seg[i].S + 1].eb(-seg[i].F);
        }
        multiset<int> st;
        map<int, int> lst;
        for(int i = 1; i <= n; i++){
            for(int j : ev[i]){
                if(j > 0) st.insert(j);
                else st.erase(st.find(-j));
            }
            if(l <= i && i <= r) continue;
            if(lst.find(a[i]) != lst.end()){
                int t = lst[a[i]];
                //cerr << "test " << i << " " << t << " " << a[i] << "\n";
                //printv(st, cerr);
                if(!st.empty() && t >= *st.begin()) owo.eb(mp(t, i));
            }
            lst[a[i]] = i;
        }
    }

    if(owo.empty()){
        cout << max(0, r - l + 1) << "\n";
        return;
    }

    lsort(owo);
    int sz = owo.size();
    vector<int> mxr(sz);
    int mnr = n;
    for(int i = 0; i < sz; i++){
        mxr[i] = owo[i].S;
        mnr = min(mnr, owo[i].S);
        if(i) mxr[i] = max(mxr[i], mxr[i - 1]); 
    }
    int ans = n;
    auto upd = [&](int tl, int tr){
        tl = min(tl, l);
        tr = max(tr, r);
        ans = min(ans, tr - tl + 1);
    };

    upd(mnr, mxr[sz - 1]);

    for(int i = sz - 1; i >= 0; i--){
        int tl = owo[i].F;
        int tr = i ? mxr[i - 1] : tl;
        upd(tl, tr);
    }

    cout << ans << "\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}