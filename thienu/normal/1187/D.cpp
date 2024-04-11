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

int INF = 1e9 + 69;

void st_set_min(vi &st, int n, int idx, int val){
    idx += n;
    st[idx] = val;
    for(;idx > 1; idx>>=1){
        st[idx>>1] = min(st[idx], st[idx^1]);
    }
}

int st_min(vi &st, int n, int left, int right){
    int ans = INF;
    for(left+=n, right+=n; left < right; left>>=1, right>>=1){
        if(left & 1) ans = min(ans, st[left++]);
        if(right & 1) ans = min(ans, st[--right]);
    }
    return ans;
}

void st_add_sum(vi &st, int n, int idx, int val){
    idx += n;
    st[idx] += val;
    for(;idx > 1; idx>>=1){
        st[idx>>1] = st[idx] + st[idx^1];
    }
}

int st_sum(vi &st, int n, int left, int right){
    int ans = 0;
    for(left+=n, right+=n; left < right; left>>=1, right>>=1){
        if(left & 1) ans += st[left++];
        if(right & 1) ans += st[--right];
    }
    return ans;
}

int st_get(vi &st, int n, int idx){
    return st[idx+n];
}

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
    }

    vi as = a, bs = b;
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    if(as != bs){
        cout << "NO" << endl;
        return;
    }

    vvi loc(n);
    vi st(2*n+2, INF); // min in loc
    vi offset(2*n+2);
    for(int i = n-1; i >= 0; i--){
        loc[a[i]].push_back(i);
        st_set_min(st, n, a[i], i);
    }
    for(int i = 0; i < n; i++){
        int nxt = *prev(loc[b[i]].end());
        debug(i, nxt);
        loc[b[i]].pop_back();
        st_set_min(st, n, b[i], loc[b[i]].empty() ? INF : *prev(loc[b[i]].end()));
        int onx = nxt;
        nxt += st_sum(offset, n, 0, nxt+1);
        debug(nxt);
        int bad_idx = st_min(st, n, 0, b[i]);
        debug(bad_idx);
        if(bad_idx < INF && bad_idx + st_sum(offset, n, 0, bad_idx+1) < nxt){
            cout << "NO" << endl;
            return;
        }
        st_add_sum(offset, n, 0, 1);
        st_add_sum(offset, n, onx+1, -1);
    }
    cout << "YES" << endl;
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