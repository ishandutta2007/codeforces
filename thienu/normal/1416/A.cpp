#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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

int INF = 1e9 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    map<int, int> last;
    map<int, int> max_diff;
    for(int i = 0; i < n; i++){
        max_diff[v[i]] = max(max_diff[v[i]], i + 1 - last[v[i]]);
        last[v[i]] = i + 1;
        debug(i, max_diff, last);
    }
    for(auto it = max_diff.begin(); it != max_diff.end(); it++){
        max_diff[it->first] = max(it->second, n + 1 - last[it->first]);
    }
    vector<int> nums(n+1, INF);
    for(auto it = max_diff.begin(); it != max_diff.end(); it++){
        nums[it->second] = min(nums[it->second], it->first);
    }
    int mini = INF;
    for(int i = 1; i <= n; i++){
        mini = min(mini, nums[i]);
        nums[i] = mini;
        cout << (nums[i] == INF ? -1 : nums[i]) << " ";
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