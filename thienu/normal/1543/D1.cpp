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

int add(int a, int b, int k){
    int ans = 0;
    int mask = 1;
    while(a > 0 || b > 0){
        int x = a % k;
        int y = b % k;
        ans += ((x+y) % k) * mask;
        mask *= k;
        a /= k;
        b /= k;
    }
    // debug(a, b, k, ans);
    return ans;
}

int neg(int a, int k){
    int ans = 0;
    int mask = 1;
    while(a > 0){
        int x = a % k;
        ans += ((k-x) % k) * mask;
        mask *= k;
        a /= k;
    }
    return ans;
}

bool answer(int guess){
    cout << guess << endl;
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x == 1;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int func = 0;
    bool plus = true;
    for(int i = 0; i < n; i++){
        int end = plus ? i : neg(i, k);
        debug(func, end);
        int guess = add(func, end, k);
        bool success = answer(guess);
        if(success) return;
        plus ^= 1;
        func = add(guess, neg(func, k), k);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}