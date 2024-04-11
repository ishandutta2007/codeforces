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

ll rt = 0;

// all letters have a run of mid
bool possible(int n, int k, string s, int mid){
    debug(mid);
    vvi can_place(k, vi(n));
    for(int i = 0; i < k; i++){
        int run = 0;
        for(int j = 0; j < n; j++){
            if(s[j]-'a' == i || s[j] == '?'){
                run++;
            }else{
                run = 0;
            }
            if(run >= mid){
                can_place[i][j] = 1;
            }
        }
    }

    // debug(can_place);

    vi dp(1<<k, -1);
    // after how many letters?
    dp[0] = 0;
    // dp, mask
    vector<deque<pair<int, int>>> process(k);
    for(int i = 0; i < k; i++){
        process[i].push_back({0, 0});
    }
    // debug(process);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(can_place[j][i]){
                int last = i-mid+1;
                // want dp <= last
                while(!process[j].empty() && process[j].front().first <= last){
                    int mask = process[j].begin()->second;
                    int new_mask = mask | (1 << j);
                    process[j].pop_front();
                    if(dp[new_mask] == -1){
                        dp[new_mask] = i+1;
                        for(int b = 0; b < k; b++){
                            if(((new_mask >> b) & 1) ^ 1){
                                process[b].push_back({i+1, new_mask});
                            }
                        }
                    }
                }
            }
        }
    }
    debug("done");

    return dp[(1<<k)-1] != -1;
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    for(int b = (1 << 20); b > 0; b >>= 1){
        int mid = ans | b;
        if(possible(n, k, s, mid)){
            ans = mid;
        }
    }
    cout << ans << endl;
    debug(rt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}