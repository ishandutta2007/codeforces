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

bool check(int n, vector<int>& a, int k){
//    cerr << "test " << k << "\n";
    vector<int> cnt(n + 1);
    std::priority_queue<pii> pq;
    deque<int> dq;
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    for(int i = 1; i <= n; i++){
        if(cnt[i]) pq.push(mp(cnt[i], i));
    }

    while(!pq.empty()){
        int now = pq.top().S;
//        cerr << now << "\n";
        pq.pop();
        dq.eb(now);
        cnt[now]--;
        if(dq.size() > k){
            int t = dq.front();
            dq.pof;
            if(cnt[t]){
                pq.push(mp(cnt[t], t));
            }
        }
    }
//    cerr << "ok " << *max_element(iter(cnt)) << "\n";
    return *max_element(iter(cnt)) == 0;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int l = 0, r = n;
        while(l < r){
            int m = (l + r + 1) / 2;
            if(check(n, a, m)) l = m;
            else r = m - 1;
        }
        cout << l << "\n";

    }

    return 0;
}