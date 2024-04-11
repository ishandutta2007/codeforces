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

struct Query{
    int left, right, idx;
    Query(int _l, int _r, int _i){
        left = _l;
        right = _r;
        idx = _i;
    }
};

void st_add(vi &st, int tl, int tr, int pos, int left, int right, int val){
    if(right < tl || tr < left){
        return;
    }
    if(left <= tl && tr <= right){
        st[pos] += val;
        return;
    }
    st_add(st, tl, tl + (tr - tl) / 2, pos * 2, left, right, val);
    st_add(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right, val);
}

int st_get(vi &st, int tl, int tr, int pos, int idx){
    if(tl == tr) return st[pos];
    // propogate
    st[2 * pos] += st[pos];
    st[2 * pos + 1] += st[pos];
    st[pos] = 0;
    if(tl + (tr - tl) / 2 >= idx){
        return st_get(st, tl, tl + (tr - tl) / 2, pos * 2, idx);
    }
    else{
        return st_get(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, idx);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = x - i - 1;
    }
    debug(v);
    vector<vector<Query>> queries(n+1);
    vi ans(q);
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        int left = x, right = n - y, idx = i;
        queries[right].push_back(Query(left, right, idx));
    }
    
    vi st(4*n);
    for(int i = 0; i < n; i++){
        // update segtree
        if(v[i] <= 0){
            int req = -v[i];
            // find rightmost >= req
            int l = -1, r = i;
            while(l < r){
                int mid = l + (r - l + 1) / 2;
                int val = st_get(st, 0, n-1, 1, mid);
                if(val >= req){
                    l = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            debug(i, req, l);
            // increment all >= req
            if(l >= 0){
                st_add(st, 0, n-1, 1, 0, l, 1);
            }
        }
        // answer queries
        for(Query q : queries[i+1]){
            int left = q.left;
            int a = st_get(st, 0, n-1, 1, left);
            debug(q.idx);
            ans[q.idx] = a;
        }
    }
    for(int i : ans){
        cout << i << '\n';
    }
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}