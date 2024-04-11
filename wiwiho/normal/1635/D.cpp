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

struct Node{
    bool v = false;
    int z = -1, o = -1;
};

vector<Node> tr;
int ts = 1;

bool check(int v, int len){
    while((v & 1) || (v % 4 == 0 && len >= 2)){
        if(v & 1){
            v >>= 1;
            len--;
        }
        else{
            v >>= 2;
            len -= 2;
        }
    }
    return len == 0;
}

int owo = 0;
int add(int now, int v, int id){
    if(id == -1) id = ts++;
    if(now == -1){
        tr[id].v = true;
        return id;
    }
    
    if(tr[id].v){
        int tmp = v & ((1 << (now + 1)) - 1);
        //cerr << "check " << v << " " << now << " " << check(tmp, now) << " " << bitset<10>(owo) << "\n";
        if(check(tmp, now + 1)) return id;
    }
    
    if(1 << now & v) owo = owo << 1 | 1, tr[id].o = add(now - 1, v, tr[id].o);
    else owo = owo << 1, tr[id].z = add(now - 1, v, tr[id].z);
    owo >>= 1;
    return id;
}

int n, p;
vector<ll> dp;

ll ans = 0;
void dfs(int id, int now){
    if(tr[id].v && now <= p){
        int tmp = p - now;
        ans += dp[tmp];
        ans %= MOD;
        //cerr << "test " << owo << " " << now << " " << tmp << " " << dp[tmp] << "\n";
    }
    owo <<= 1;
    if(tr[id].z != -1) dfs(tr[id].z, now + 1);
    owo |= 1;
    if(tr[id].o != -1) dfs(tr[id].o, now + 1);
    owo >>= 1;
}

int main(){
    StarBurstStream;

    cin >> n >> p;

    tr.resize(30 * n + 100);

    dp.resize(p + 1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= p; i++){
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= MOD;
    }
    //printv(dp, cerr);
    for(int i = 1; i <= p; i++) dp[i] = (dp[i] + dp[i - 1]) % MOD;
    //printv(dp, cerr);

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    lsort(a);
    for(int i = 1; i <= n; i++){
        //cerr << a[i] << " " << bitset<10>(a[i]) << "\n";
        add(__lg(a[i]), a[i], 0);
    }

    dfs(0, 0);
    cout << ans << "\n";

    return 0;
}