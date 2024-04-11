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


#define int long long
int N = 1e5;

vector<int> lp(N);
vector<int> pr;

void solve(){

    ll p, q;
    cin >> p >> q;
    if(p % q != 0){
        cout << p << endl;
        return;
    }
    bool prime = true;
    for(int pp : pr){
        if(q % pp == 0 && q != pp) prime = false;
    }

    if(prime){
        while(p % q == 0) p /= q;
        cout << p << endl;
        return;
    }

    // get prime factors
    set<int> factors;
    for(int pp : pr){
        if(q % pp == 0) factors.insert(pp);
    }

    ll ans = 0;

    for(int f : factors){
        ll x = p;
        while(x % q == 0) x /= f;
        debug(f, x);
        ans = max(ans, x);
    }
    cout << ans << endl;
}

#undef int
int main(){
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++){
            lp[i * pr[j]] = pr[j];
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}