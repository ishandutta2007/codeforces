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

vi st, d;
int n, h;

void calc(int pos, int sz){
    if(d[pos] == -1) st[pos] = st[pos<<1] + st[pos<<1|1];
    else st[pos] = d[pos] * sz;
}

void apply(int pos, int val, int sz){
    st[pos] = val * sz;
    if(pos < n) d[pos] = val;
}

void build(int l, int r) {
    int k = 2;
    for (l += n, r += n-1; l > 1; k <<= 1) {
        l >>= 1, r >>= 1;
        for (int i = r; i >= l; --i) calc(i, k);
    }
}

void push(int l, int r){
    int s = h, k = 1<<(h-1);
    for(l += n, r += n-1; s > 0; s--, k>>=1){
        for(int i = l>>s; i <= r>>s; i++){
            if(d[i] != -1){
                apply(i<<1, d[i], k);
                apply(i<<1|1, d[i], k);
                d[i] = -1;
            }
        }
    }
}

void modify(int l, int r, int val){
    if(val == -1) return;
    push(l, l+1);
    push(r-1, r);
    int l0 = l, r0 = r, k = 1;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1){
        if(l&1) apply(l++, val, k);
        if(r&1) apply(--r, val, k);
    }
    build(l0, l0+1);
    build(r0-1, r0);
}

int query(int l, int r){
    push(l, l+1);
    push(r-1, r);
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) res += st[l++];
        if(r&1) res += st[--r];
    }
    return res;
}

void solve(){
    int q;
    cin >> n >> q;
    h = 32 - __builtin_clz(n);
    st.resize(2*n+2);
    d.resize(n+1);
    fill(d.begin(), d.end(), -1);
    fill(st.begin(), st.end(), 0);

    string s, t;
    cin >> s >> t;

    vpii ops;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        ops.push_back({x, y});
    }

    for(int i = 0; i < n; i++){
        st[i+n] = t[i]-'0';
    }
    build(0, n);
    for(int i = q-1; i >= 0; i--){
        debug(i);
        int l = ops[i].first, r = ops[i].second;
        int a = query(l, r);
        // debug(l, r, a);
        if((((r^l)&1)^1) && a == (r-l)/2){
            cout << "NO" << endl;
            return;
        }
        int v = (a > (r-l)/2) ? 1 : 0;
        // debug(v);
        modify(l, r, v);
    }
    push(0, n);
    for(int i = 0; i < n; i++){
        debug(st[i+n]);
        if(st[i+n] != s[i]-'0'){
            cout << "NO" << endl;
            return;
        }
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