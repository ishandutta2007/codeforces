
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

void test(){
    const int n = 5, k = 2;

    int st = 0;
    for(int i = 0; i < k; i++) st |= 1 << i;
    vector<bool> vst(1 << n);
    vst[st] = true;
    queue<int> q;
    q.push(st);
    int ans = 0;
    while(!q.empty()){
        int now = q.front();
        ans++;
        cerr << bitset<n>(now) << "\n";
        q.pop();
        for(int i = 0; i < n; i++){
            if(!(1 << i & now)) continue;
            if(i >= 2 && (1 << (i - 1) & now) && !(1 << (i - 2) & now)){
                int go = now | (1 << (i - 2));
                go ^= 1 << i;
                if(!vst[go]){
                    vst[go] = true;
                    q.push(go);
                }
            }
            if(i < n - 2 && (1 << (i + 1) & now) && !(1 << (i + 2) & now)){
                int go = now | (1 << (i + 2));
                go ^= 1 << i;
                if(!vst[go]){
                    vst[go] = true;
                    q.push(go);
                }
            }
        }
    }
    cout << ans << "\n";
}

ll inv(ll a){
    ll b = MOD - 2;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

vector<ll> f;

ll C(ll n, ll k){
    return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    int one = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(cnt % 2) cnt--;
            continue;
        }
        one++;
        cnt++;
    }
    if(cnt % 2) cnt--;
    n -= one - cnt;
//    cerr << n << " " << cnt << "\n";
    cnt /= 2;
//    cerr << f[0] << "\n";
    if(cnt == 0){
        cout << "1\n";
        return;
    }

    ll ans = 0;
    for(int i = 2 * cnt - 1; i < n; i++){
//        cerr << C(cnt - 1 + (i - (2 * cnt - 1)), i - (2 * cnt - 1)) << " ";
        ans += C(cnt - 1 + (i - (2 * cnt - 1)), i - (2 * cnt - 1));
        ans %= MOD;
    }
//    cerr << "\n";
    cout << ans << "\n";

}

int main(){
    StarBurstStream

    f.resize(100001);
    f[0] = 1;
    for(int i = 1; i <= 100000; i++){
        f[i] = f[i - 1] * i % MOD;
    }

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}