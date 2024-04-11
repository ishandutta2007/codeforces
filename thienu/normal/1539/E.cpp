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

const int B = 350;
// const int B = 2;

pii int_union(pii a, pii b){
    pii out = {max(a.first, b.first), min(a.second, b.second)};
    if(out.first > out.second) return {-1, -2};
    return out;
}

bool int_contains(pii a, int x){
    return a.first <= x && x <= a.second;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vi cards(n+1);
    vector<vpii> intervals;
    intervals.push_back({{0, 0}, {0, 0}});
    for(int i = 0; i < n; i++){
        cin >> cards[i+1];
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        intervals.push_back({{a, b}, {c, d}});
    }
    debug(cards, intervals);
    vvi expiry(n+1, vi(2));
    for(int h = 0; h < 2; h++){
        // sqrt decomp
        int num_blocks = n / B + 1;
        vpii block_union;
        for(int s = 0; s <= n; s+=B){
            pii u = {0, m};
            for(int i = s; i < min(s+B, n+1); i++){
                u = int_union(u, intervals[i][h]);
            }
            block_union.push_back(u);
        }
        debug(block_union);
        
        for(int i = 0; i <= n; i++){
            debug(h, i);
            int cur = i;
            pii interval = {0, m};
            while(cur % B != 0 && cur <= n){
                interval = int_union(interval, intervals[cur][h]);
                if(!int_contains(interval, cards[i])){
                    expiry[i][h] = cur;
                    goto continue_for;
                }
                cur++;
            }
            if(cur > n){
                expiry[i][h] = n+1;
                continue;
            }
            while(cur <= n){
                pii new_interval = int_union(interval, block_union[cur / B]);
                debug(cur, new_interval, cards[i], int_contains(interval, cards[i]));
                if(int_contains(new_interval, cards[i])){
                    interval = new_interval;
                    cur += B;
                }
                else{
                    break;
                }
            }
            if(cur > n){
                expiry[i][h] = n+1;
                continue;
            }
            while(cur <= n){
                interval = int_union(interval, intervals[cur][h]);
                if(!int_contains(interval, cards[i])){
                    expiry[i][h] = cur;
                    goto continue_for;
                }
                cur++;
            }
            if(cur > n){
                expiry[i][h] = n+1;
                continue;
            }
            continue_for:
            continue;
        }
    }
    debug(expiry);

    // maximum exp of other card
    vvi dp(n+1, vi(2));
    // hand of previous card
    vvi parent(n+1, vi(2, -1));

    dp[0][0] = expiry[0][1];
    dp[0][1] = expiry[0][0];

    // start dp
    for(int i = 1; i <= n; i++){
        for(int h = 0; h < 2; h++){
            if(expiry[i][h] == i){
                dp[i][h] = -1;
                continue;
            }
            int same = dp[i-1][h];
            if(same <= i) same = -1;
            int different = expiry[i-1][!h];
            if(different <= i || dp[i-1][!h] == -1) different = -1;
            debug(i, h, same, different);
            if(same > different){
                dp[i][h] = same;
                parent[i][h] = h;
            }
            else{
                dp[i][h] = different;
                parent[i][h] = !h;
            }
        }
    }
    debug(dp);
    if(max(dp[n][0], dp[n][1]) == -1){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    int hand = (dp[n][0] == -1 ? 1 : 0);
    vi ans;
    for(int i = n; i >= 1; i--){
        ans.push_back(hand);
        hand = parent[i][hand];
    }
    debug(ans);
    reverse(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}