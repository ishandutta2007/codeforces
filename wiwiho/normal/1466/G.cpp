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

int kmp(string& s, string& t, int p){
    int n = s.size(), m = t.size();
    vector<int> f(m);
    f[0] = -1;
    int now = -1;
    for(int i = 1; i < m; i++){
        while(now != -1 && t[i] != t[now + 1]) now = f[now];
        if(t[i] == t[now + 1]) now++;
        f[i] = now;
    }

    int ans = 0;
    now = -1;
    for(int i = 0; i < n; i++){
        while(now == m - 1 || (now != -1 && s[i] != t[now + 1])) now = f[now];
        if(s[i] == t[now + 1]) now++;
        if(now == m - 1){
            if(p == -1) ans++;
            else if(i - m + 1 <= p && i >= p) ans++;
        }
    }
//    cerr << "kmp " << s << " " << t << " " << p << " " << ans << "\n";

    return ans;
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

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    string s, t;
    cin >> s >> t;
    vector<ll> two(n + 1);
    vector<ll> invt(n + 1);
    two[0] = 1;
    for(int i = 1; i <= n; i++) two[i] = two[i - 1] * 2 % MOD;
    for(int i = 0; i <= n; i++) invt[i] = inv(two[i]);
    vector<vector<int>> sum(26, vector<int>(n + 1));
    for(int i = 0; i < n; i++){
        sum[t[i] - 'a'][i + 1] += two[n - i - 1];
        sum[t[i] - 'a'][i + 1] %= MOD;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= n; j++) sum[i][j] += sum[i][j - 1], sum[i][j] %= MOD;
    }


    while(q--){

        int nn = n;
        int n;
        cin >> n;
        string w;
        cin >> w;

        string ok = s;
        int k = 0;
        while(ok.size() < w.size() && k < n){
            ok = ok + t[k] + ok;
            k++;
        }
        if(ok.size() < w.size()){
            cout << "0\n";
            continue;
        }

        ll ans = kmp(ok, w, -1) * two[n - k] % MOD;

        for(int i = 0; i < 26; i++){
            string tmp = ok + (char)('a' + i) + ok;
            ll cnt = kmp(tmp, w, ok.size());
            ll qaq = (sum[i][n] - sum[i][k] + MOD) % MOD;
            qaq *= invt[nn - n];
            qaq %= MOD;
//            cerr << i << ' ' << k << " " << n - 1 << " " << qaq << "\n";
            ans += (cnt * qaq) % MOD;
            ans %= MOD;
        }

        cout << ans << "\n";

    }

    return 0;
}