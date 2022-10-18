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

int lowbit(int x){
    return x & -x;
}

vector<int> BIT;

void modify(int x, int v){
    x++;
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
    }
}

int query(int x){
    x++;
    int ans = 0;
    for(; x > 0; x-= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}

void solve(){

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    BIT.clear();
    BIT.resize(n + 1);
    for(int i = 0; i < n; i++) modify(i, 1);

    if(s < t){
        cout << "0\n";
        return;
    }

    string tmp = s;
    lsort(tmp);
    if(tmp >= t){
        cout << "-1\n";
        return;
    }

    vector<queue<int>> pos(26);
    for(int i = 0; i < n; i++){
        pos[s[i] - 'a'].push(i);
    }
    vector<bool> use(n + 1);

    ll ans = 1LL << 60;
    ll now = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < t[i] - 'a'; j++){
            if(!pos[j].empty()){
                int tp = pos[j].front();
                ans = min(ans, now + query(tp) - 1);
            }
        }

        if(pos[t[i] - 'a'].empty()) break;
        int tp = pos[t[i] - 'a'].front();
        pos[t[i] - 'a'].pop();
        now += query(tp) - 1;
        modify(tp, -1);
    }

    cout << ans << "\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}