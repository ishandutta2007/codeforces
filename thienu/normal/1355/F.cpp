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

const int M = 10000;
vi primes;

void precalc(){
    for(int i = 2; i < M; i++){
        bool pr = true;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                pr = false;
                break;
            }
        }
        if(pr) primes.push_back(i);
    }
}

ll query(ll x){
    assert(x <= (ll) 1e18);
    cout << "? " << x << endl;
    ll g;
    cin >> g;
    return g;
}

ll answer(ll x){
    cout << "! " << x << endl;
}

ll last_exp(ll x){
    ll ans = 1;
    while(ans * x < (ll) 1e9){
        ans *= x;
    }
    return ans;
}

ll dlog(ll x, ll base){
    ll ans = 0;
    while(x % base == 0){
        ans++;
        x /= base;
    }
    return ans;
}

void solve(){
    ll cur = 1;
    vll detected_primes;
    int p = 0;
    while(p == 0 || (1LL * cur * primes[p-1] * primes[p-1] * primes[p-1] <= (ll) 1e9 && primes[p-1] < 630)){
        ll q = 1;
        vll query_p;
        while(q < (ll) 1e18 / (ll) primes[p]){
            q *= primes[p];
            query_p.push_back(primes[p]);
            p++;
        }
        ll out = query(q);
        for(ll p : query_p){
            if(out % p == 0){
                detected_primes.push_back(p);
                cur *= p;
            }
        }
    }
    ll guess = 1;
    ll factors = 1;
    debug(detected_primes);
    for(int i = 0; i < detected_primes.size(); i+=2){
        if(i == detected_primes.size() - 1){
            ll out = query(last_exp(detected_primes[i]));
            guess *= out;
            factors *= (dlog(out, detected_primes[i])+1);
        }else{
            ll out = query(last_exp(detected_primes[i]) * last_exp(detected_primes[i+1]));
            guess *= out;
            factors *= ((dlog(out, detected_primes[i])+1) * (dlog(out, detected_primes[i+1])+1));
        }
    }
    debug(guess);
    if(guess == 1){
        answer(8);
    }else if(guess <= 3){
        answer(9);
    }else{
        answer(2 * factors);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}