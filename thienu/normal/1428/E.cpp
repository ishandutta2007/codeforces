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

ll calc(ll num, ll sqs){
    // split num into sqs
    ll a = num % sqs;
    ll b = sqs - a;
    ll x = num / sqs;
    return x * x * b + (x+1) * (x+1) * a;
}

#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    vpii v;
    set<pair<ll, int>, greater<pair<ll, int>>> nums;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back({x, 1});
        sum += x * x;
        nums.insert({calc(x, 1) - calc(x, 2), i});
    }

    debug(nums, sum);
    
    for(int total = n; total < k; total++){
        auto p = *nums.begin();
        ll red = p.first;
        int i = p.second;
        int x = v[i].first;
        int occ = v[i].second;
        sum -= red;
        debug(total, nums, sum, v, calc(x, occ), calc(x, occ + 1));
        nums.erase(nums.begin());
        nums.insert({calc(x, occ + 1) - calc(x, occ + 2), i});
        v[i].second++;
    }

    cout << sum << endl;
}

#undef int long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}