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

const int A = 1e6 + 420;
// const int A = 20;
vi st(2*A);
vi d(2*A);
// int st[2*A];
// int d[2*A];

int m, h;

const int INF = 1e9 + 7;

void apply(int pos, int val){
    debug(pos, val);
    st[pos] += val;
    if(pos < m) d[pos] += val;
}

void build(int l, int r){
    debug("build", l, r);
    for(l += m, r += m-1; l > 1;){
        l >>= 1, r >>= 1;
        for(int i = r; i >= l; i--){
            st[i] = min(st[i<<1], st[i<<1|1]) + d[i];
        }
    }
}

void push(int l, int r){
    int s = h;
    for(l += m, r += m-1; s > 0; s--){
        for(int i = l>>s; i <= r>>s; i++){
            if(d[i] != 0){
                apply(i<<1, d[i]);
                apply(i<<1|1, d[i]);
                d[i] = 0;
            }
        }
    }
}

void inc(int l, int r, int val){
    debug("inc", l, r, val);
    int l0 = l, r0 = r;
    l += m, r += m;
    for(; l < r; l>>=1, r>>=1){
        if(l&1) apply(l++, val);
        if(r&1) apply(--r, val);
    }
    debug(l0, r0);
    build(l0, l0+1);
    build(r0-1, r0);
}

int query(int l, int r){
    debug("query", l, r);
    l += m, r += m;
    push(l, l+1);
    push(r-1, r);
    int res = INF;
    for(; l < r; l >>= 1, r >>= 1){
        if(l&1) res = min(res, st[l++]);
        if(r&1) res = min(res, st[--r]);
    }
    return res;
}

void solve(){
    int n;
    cin >> n >> m;
    h = 8*sizeof(int)-__builtin_clz(m);

    vector<pair<int, pii>> seg;
    for(int i = 0; i < n; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        seg.push_back({w, {x, y}});
    }

    sort(seg.begin(), seg.end());

    int ans = INF;
    fill(st.begin(), st.end(), 0);
    fill(d.begin(), d.end(), 0);
    auto p1 = seg.begin(), p2 = seg.begin();
    while(p2 != seg.end()){
        inc(p2->second.first, p2->second.second, 1);
        while(query(0, m-1) >= 1){
            ans = min(ans, p2->first-p1->first);
            inc(p1->second.first, p1->second.second, -1);
            p1++;
        }
        p2++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}