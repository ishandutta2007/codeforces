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

void solve(){
    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;

    if(n == 1){
        cout << (1LL << (s[0] - 'a') == t ? "Yes" : "No") << endl;
        return;
    }
    if(n == 2){
        cout << ((1LL << (s[1] - 'a')) - (1ll << (s[0] - 'a')) == t ? "Yes" : "No") << endl;
        return;
    }

    ll target = t - ((1LL << (s[n-1] - 'a')) - (1ll << (s[n-2] - 'a')));

    debug(target);

    // knapsack
    vi cnt(26);
    for(int i = 0; i < n-2; i++){
        cnt[s[i] - 'a']++;
        target -= 1LL << (s[i] - 'a');
    }
    debug(cnt, target);

    for(int i = 25; i >= 0; i--){
        while(cnt[i] > 0 && target + (1LL << (i + 1)) <= 0){
            target += (1LL << (i + 1));
            debug(target);
            cnt[i]--;
        }
    }

    cout << (target == 0 ? "Yes" : "No") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}