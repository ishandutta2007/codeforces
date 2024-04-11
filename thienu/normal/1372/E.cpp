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

// upsolved

void solve(){
    int n, m;
    cin >> n >> m;
    vector<multiset<pair<int, int>>> intervals(m);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a, b;
            cin >> a >> b;
            a--;b--;
            for(int k = a; k <= b; k++){
                intervals[k].insert(make_pair(a, b));
            }
        }
    }


    debug(intervals);

    // dp[l][r] is answer for l to r
    vector<vector<int>> dp(m, vector<int>(m));
    for(int delta = 0; delta < m; delta++){
        for(int l = 0; l + delta < m; l++){
            int r = l + delta;
            debug(l, r, dp);
            int maxi = 0;
            for(int k = l; k <= r; k++){
                // use k
                int cnt = 0;
                for(pair<int, int> p : intervals[k]){
                    if(p.first >= l && p.second <= r) cnt++;
                }
                debug(k, maxi);
                maxi = max(maxi, cnt * cnt + (k > 0 ? dp[l][k-1] : 0) + (k+1 < m ? dp[k+1][r] : 0));
            }
            dp[l][r] = maxi;
        }
    }
    cout << dp[0][m-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}