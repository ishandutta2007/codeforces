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

int pow2(int n){
    int ans = 1;
    while(n--) ans *= 2;
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int total = pow2(n);
    vector<vector<int>> rows(n+1, vector<int>());
    for(int i = 0; i < total; i++){
        int x;
        cin >> x;
        rows[0].push_back(x);
    }

    // populate tree
    for(int i = 1; i <= n; i++){
        int num_nodes = pow2(n-i);
        for(int j = 0; j < num_nodes; j++){
            rows[i].push_back(i & 1 ? rows[i-1][2*j] | rows[i-1][2*j+1] : rows[i-1][2*j] ^ rows[i-1][2*j+1]);
        }
    }

    debug(rows);

    // process queries
    for(int q = 0; q < m; q++){
        int p, b;
        cin >> p >> b;
        --p;
        rows[0][p] = b;

        // propogate
        for(int i = 1; i <= n; i++){
            p /= 2;
            rows[i][p] = i & 1 ? rows[i-1][2*p] | rows[i-1][2*p+1] : rows[i-1][2*p] ^ rows[i-1][2*p+1];
        }

        cout << rows[n][0] << endl;
        debug(rows);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}