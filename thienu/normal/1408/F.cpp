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

vector<pair<int, int>> ans;

void sub(int left, int right, int n){
    if(n == 0) return;
    if(n == 1){
        ans.push_back({left, right});
        return;
    }
    sub(left, left + (1 << (n-1)) - 1, n-1);
    sub(right - (1 << (n-1)) + 1, right, n-1);
    for(int i = left; i < left + (1 << (n-1)); i++){
        ans.push_back({i, i + (1 << (n-1))});
    }
}


void solve(){
    int n;
    cin >> n;
    int log = 0;
    while(1 << (log + 1) <= n) log++;
    debug(log);
    sub(1, 1 << log, log);
    sub(n - (1 << log) + 1, n, log);
    debug(ans.size());
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}