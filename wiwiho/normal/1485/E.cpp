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
const ll LLMAX = 1LL << 60;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        vector<vector<int>> g(n + 1);
        vector<int> p(n + 1), a(n + 1);

        for(int i = 2; i <= n; i++){
            cin >> p[i];
            g[p[i]].eb(i);
        }
        for(int i = 2; i <= n; i++) cin >> a[i];

        vector<int> dpt(n + 1);
        vector<vector<int>> dv(n);
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i : g[now]){
                q.push(i);
                dpt[i] = dpt[now] + 1;
            }
        }
        for(int i = 1; i <= n; i++) dv[dpt[i]].eb(i);
        while(dv.back().empty()) dv.pob;
        int m = dv.size();

        vector<ll> dp(n + 1);
        for(int d = 1; d < m; d++){
            vector<pll> tmp;
            int mx = 0, mn = MAX;
            for(int i : dv[d - 1]){
                tmp.eb(mp(a[i], i));
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
            lsort(tmp);
            vector<ll> t(tmp.size() + 1);
            vector<ll> pre(tmp.size() + 2, -MAX), suf(tmp.size() + 2, -MAX);
            for(int i = 1; i <= tmp.size(); i++){
                int now = tmp[i - 1].S;
                t[i] = tmp[i - 1].F;
                pre[i] = dp[now] - a[now];
                suf[i] = dp[now] + a[now];
                pre[i] = max(pre[i], pre[i - 1]);
            }
            for(int i = tmp.size(); i >= 1; i--) suf[i] = max(suf[i], suf[i + 1]);
//            cerr << "test " << d << "\n";
//            printv(t, cerr);
//            printv(suf, cerr);
//            printv(pre, cerr);

            for(int i : dv[d]){
                auto it = lower_bound(iter(t), a[p[i]]);
                dp[i] = suf[it - t.begin()] - a[p[i]];
                if(it != t.begin()){
                    dp[i] = max(dp[i], pre[it - t.begin() - 1] + a[p[i]]);
                }
//                cerr << "test " << i << " " << dp[i] << " ";
                dp[i] = max({dp[i], dp[p[i]] + a[p[i]] - mn, dp[p[i]] + mx - a[p[i]]});
//                cerr << dp[i] << "\n";
            }
        }
//        printv(dpt, cerr);
//        printv(a, cerr);
//        printv(dp, cerr);

        ll ans = 0;
        int mx = 0;
        int mn = MAX;
        for(int i : dv[m - 1]){
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        for(int i : dv[m - 1]){
            ans = max({ans, dp[i] + a[i] - mn, dp[i] + mx - a[i]});
        }
        cout << ans << "\n";

    }

    return 0;
}