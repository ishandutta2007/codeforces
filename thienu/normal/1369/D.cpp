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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int MAXI = 2e6;
// int MAXI = 10;
ll MOD = 1e9 + 7;

void solve(){
    vector<ll> ans(MAXI+1);
    vector<int> free(MAXI+1);
    ans[0] = 0;
    free[0] = false;
    ans[1] = 0;
    free[1] = true;
    for(int i = 2; i <= MAXI; i++){
        ll x = (ans[i-1] + 2 * ans[i-2]) % MOD;
        if(free[i-1] && free[i-2]){
            free[i] = false;
            ans[i] = (x + 1) % MOD;
        }
        else{
            free[i] = true;
            ans[i] = x;
        }
    }

    // debug(ans, free);

    int tc;
    cin >> tc;
    while(tc--){
        int x;
        cin >> x;
        cout << (ans[x] * 4 % MOD) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}