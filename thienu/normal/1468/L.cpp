#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ll> factor(ll n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ll x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    map<ll, vll> ppower;
    vector<pair<ll, set<ll>>> facts;
    for(int i = 0; i < n; i++){
        vll f = factor(v[i]);
        set<ll> factors;
        for(ll j : f){
            factors.insert(j);
        }
        if(factors.size() == 1){
            ppower[*factors.begin()].push_back(v[i]);
        }else{
            facts.push_back({v[i], factors});
        }
    }
    // debug(ppower[2], facts[0].second);

    int total_ppower = 0;
    vi sizes;
    vll bases;
    for(auto it = ppower.begin(); it != ppower.end(); it++){
        if(it->second.size() > 1){
            total_ppower += it->second.size();
            sizes.push_back(it->second.size());
            bases.push_back(it->first);
        }
    }

    debug(sizes);
    
    vll ans;
    if(total_ppower < k){
        set<ll> pr;
        for(auto it = ppower.begin(); it != ppower.end(); it++){
            if(it->second.size() > 1){
                for(ll j : it->second){
                    ans.push_back(j);
                }
                pr.insert(it->first);
            }
        }
        debug(ans, pr);
        for(pair<ll, set<ll>> cand : facts){
            if(ans.size() == k) break;
            for(int j : cand.second){
                // debug(j, pr);
                if(pr.find(j) == pr.end()){
                    goto end1;
                }
            }
            ans.push_back(cand.first);
            end1:;
        }
        if(ans.size() != k){
            cout << 0 << endl;
            return;
        }
    }else{
        vvi dp(sizes.size() + 1, vi(k+1, -1));
        dp[0][0] = 0;
        debug(sizes);
        debug(sizes.size());
        for(int i = 0; i < sizes.size(); i++){
            for(int j = 0; j <= k; j++){
                if(dp[i][j] == -1) continue;
                dp[i+1][j] = 0;
                for(int x = 2; j + x <= k && x <= sizes[i]; x++){
                    dp[i+1][j+x] = x;
                }
            }
        }
        debug(dp);
        int cur = k;
        if(dp[sizes.size()][cur] == -1){
            cur--;
        }
        debug(cur);
        for(int i = sizes.size() - 1; i >= 0; i--){
            int x = dp[i+1][cur];
            for(int j = 0; j < x; j++){
                ans.push_back(ppower[bases[i]][j]);
            }
            cur -= x;
        }
        debug(ans);

        if(ans.size() < k){
            debug("no");
            ans.clear();
            set<ll> pr;
            for(auto it = ppower.begin(); it != ppower.end(); it++){
                if(it->second.size() > 1) pr.insert(it->first);
            }
            debug(pr);
            bool ok = false;
            for(pair<ll, set<ll>> cand : facts){
                int pf = 0;
                for(ll j : cand.second){
                    if(pr.find(j) == pr.end()){
                        goto end2;
                    }
                    pf++;
                }
                if(2 * pf + 1 <= k){
                    debug(cand.first);
                    ans.push_back(cand.first);
                    for(ll j : cand.second){
                        for(ll x : ppower[j]){
                            ans.push_back(x);
                        }
                        pr.erase(j);
                    }
                    ok = true;
                    break;
                }
                end2:;
            }
            if(!ok){
                cout << 0 << endl;
                return;
            }
            for(ll i : pr){
                if(ans.size() >= k) break;
                for(ll j : ppower[i]){
                    ans.push_back(j);
                }
            }
        }
    }
    for(ll i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}