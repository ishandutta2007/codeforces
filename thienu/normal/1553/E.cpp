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

bool test(vi &v, int n, int k, int rot){
    vi p(n);
    for(int i = 0; i < n; i++){
        p[i] = v[(i+rot)%n];
    }
    debug(rot, p);
    int swaps = 0;
    vi vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int cur = i;
        vis[i] = 1;
        int len = 1;
        cur = p[cur];
        while(cur != i){
            vis[cur] = 1;
            len++;
            cur = p[cur];
        }
        swaps += len-1;
    }
    debug(swaps);
    return swaps <= k;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n), delta(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
        delta[i] = (i-v[i]+n)%n;
    }
    debug(delta);
    vi cnt(n);
    for(int i : delta){
        cnt[i]++;
    }
    vi cand;
    for(int i = 0; i < n; i++){
        if(cnt[i] >= n-(2*k)){
            cand.push_back(i);
        }
    }
    debug(cand);

    vi ans;
    for(int i : cand){
        if(test(v, n, k, i)){
            ans.push_back(i);
        }
    }
    cout << ans.size();
    for(int i : ans){
        cout << ' ' << i;
    }
    cout << endl;
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