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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi runs;
    int ans = 0, run = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            runs.push_back(run);
            run = 0;
            ans += (i == 0 || s[i-1] == 'L') ? 1 : 2;
        }
        else{
            run++;
            cnt++;
        }
    }
    runs.push_back(run);
    debug(runs);
    if(runs.size() == 1){
        ans += (k ? 2 * k - 1 : 0);
        cout << ans << endl;
        return;
    }
    vi pruned = vi(next(runs.begin()), prev(runs.end()));
    debug(pruned);
    multiset<int> ss;
    for(int i : pruned){
        ss.insert(i);
    }
    debug(ss);
    k = min(k, cnt);
    while(!ss.empty() && *ss.begin() <= k){
        if(*ss.begin() == 0){
            ss.erase(ss.begin());
            continue;
        }
        k -= *ss.begin();
        ans += 2 * (*ss.begin()) + 1;
        ss.erase(ss.begin());
    }
    ans += 2 * k;
    cout << ans << endl;
    return;
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