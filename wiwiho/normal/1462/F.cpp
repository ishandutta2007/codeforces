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

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
    }
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        vector<int> p;
        vector<int> l(n), r(n);
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
            p.eb(l[i]);
            p.eb(r[i]);
        }
        p.eb(0);
        lsort(p);
        uni(p);

        vector<vector<int>> e(p.size());
        BIT.resize(p.size());
        for(int i = 0; i < n; i++){
            l[i] = lower_bound(iter(p), l[i]) - p.begin();
            r[i] = lower_bound(iter(p), r[i]) - p.begin();
            e[l[i]].eb(r[i]);
            modify(l[i], 1);
        }

        int ans = n;
        for(int i = 1; i < p.size(); i++){
            for(int j : e[i]){
                ans = min(ans, n - query(j));
            }
            for(int j : e[i]) modify(j, 1);
            modify(i, -(query(i) - query(i - 1)));
        }
        cout << ans << "\n";

    }


    return 0;
}