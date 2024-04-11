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

int INF = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vi v;
    int k = -1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i && (x == k)) continue;
        v.push_back(x);
        k = x;
    }
    n = v.size();

    // debug("init");

    vi next_idx(n, INF);
    vi last(n + 2, INF);
    for(int i = n-1; i >= 0; i--){
        next_idx[i] = last[v[i]];
        last[v[i]] = i;
    }
    debug(next_idx);
    int ans = 0;
    int a = -1, b = -1;
    for(int i = 0; i < n; i++){
        debug(i, a, b, ans);
        if(a == -1){
            a = i;
            ans++;
        }
        else if(v[i] == v[a]){
            a = i;
        }
        else if(b == -1){
            b = i;
            ans++;
        }
        else if(v[i] == v[b]){
            b = i;
        }
        else if(next_idx[a] < next_idx[b]){
            b = i;
            ans++;
        }
        else{
            a = i;
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}