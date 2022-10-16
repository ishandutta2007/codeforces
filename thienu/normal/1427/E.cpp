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

vector<tuple<ll, char, ll>> ans;

void binmul(ll a, ll b){
    ll cur = 0;
    ll pow = a;
    while(b){
        if(b & 1){
            ans.push_back({cur, '+', pow});
            cur += pow;
        }
        ans.push_back({pow, '+', pow});
        pow += pow;
        b >>= 1;
    }
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve(){
    ll n;
    cin >> n;
    ans.push_back({n, '^', n}); 


    ll i = 1;
    while(__gcd(n, n ^ (n * i)) != 1){
        i++;
    }
    debug(i);
    binmul(n, i);

    ans.push_back({n * i, '^', n});

    ll x = (n * i) ^ n;

    debug(n, x);

    // solve an = bx + 1
    // an - bx = 1

    ll a, b;
    gcd(n, x, a, b);
    b = -b;
    while(a < 0 || b < 0){
        a += x;
        b += n;
    }
    debug(n, x, a, b);
    
    if(((a * n) ^ (b * x)) != 1){
        a = x - a;
        b = n - b;
    }
    if(((a * n) ^ (b * x)) != 1){
        a += x;
        b += n;
    }
    while(a < 0 || b < 0){
        a += x;
        b += n;
    }

    debug(n, x, a, b);

    binmul(n, a);
    binmul(x, b);

    ans.push_back({(n * a), '^', (x * b)});



    cout << ans.size() << endl;
    for(auto t : ans){
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}