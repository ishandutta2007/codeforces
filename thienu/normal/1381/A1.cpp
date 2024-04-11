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

void solve(){
    int n;
    cin >> n;
    string u, v;
    cin >> u >> v;
    vector<int> ans;
    bool flipped = false;
    vector<int> num_flips(n);
    for(int i = 0; i < n; i++){
        int idx = i & 1 ? i / 2 + 1 : n - 1 - i / 2;
        int front = i & 1 ? n-1-i/2 : i/2;
        bool is_flipped = ((num_flips[front] & 1 && !flipped) || (!num_flips[front] & 1 && flipped));
        debug(i, idx, front, u[idx], v[n-i-1], is_flipped, num_flips, ans);
        if((u[front] == v[n-i-1] && !is_flipped) || (u[front] != v[n-i-1] && is_flipped)){
            ans.push_back(1);
            num_flips[front]++;
        }
        ans.push_back(n-i);
        flipped = !flipped;
    }
    cout << ans.size() << " ";
    for(int i : ans) cout << i << " ";
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