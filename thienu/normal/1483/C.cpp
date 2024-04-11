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

ll INF = (ll) 2e18 + 7;

// max segtree
void st_set(vll &st, int tl, int tr, int pos, int sp, ll sv){
    // debug("set")
    if(tl == tr){
        st[pos] = sv;
        return;
    }
    if(sp <= tl + (tr - tl) / 2){
        st_set(st, tl, tl + (tr - tl) / 2, pos * 2, sp, sv);
    }
    else{
        st_set(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, sp, sv);
    }
    st[pos] = max(st[2 * pos], st[2 * pos + 1]);
}

ll st_max(vll &st, int tl, int tr, int pos, int left, int right){
    if(tr < left || right < tl) return -INF;
    if(left <= tl && tr <= right){
        return st[pos];
    }
    return max(
        st_max(st, tl, tl + (tr - tl) / 2, pos * 2, left, right),
        st_max(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right)
    );
}

void solve(){
    int n;
    cin >> n;
    vi p(n);
    vi b(n);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        p[i] = x-1;
    }
    for(int i = 0; i < n; i++) cin >> b[i];

    vll st(4 * n, -INF);
    
    vll dp(n);
    dp[0] = b[0];
    st_set(st, 0, n-1, 1, 0, b[0]);

    stack<int> heights;
    heights.push(0);
    for(int i = 1; i < n; i++){
        while(!heights.empty() && p[heights.top()] > p[i]){
            debug(i, heights.top(), p[heights.top()]);
            heights.pop();
        }
        debug(heights.size());
        ll cur = -INF;
        int j;

        if(!heights.empty()){
            j = heights.top();
            cur = dp[j];
        }
        else{
            cur = b[i];
            j = 0;
        }
        debug(i, j, cur);
        cur = max(cur, st_max(st, 0, n-1, 1, j, i-1) + b[i]);
        dp[i] = cur;
        debug(i, dp[i]);
        st_set(st, 0, n-1, 1, i, dp[i]);

        heights.push(i);
    }
    cout << dp[n-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}