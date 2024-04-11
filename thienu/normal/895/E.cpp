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

vd st, lazy_linear, lazy_const;
vi st_sz;

void st_build(int tl, int tr, int pos, vd &v){
    if(tl == tr){
        st[pos] = v[tl];
        st_sz[pos] = 1;
        return;
    }
    st_build(tl, tl + (tr - tl) / 2, pos * 2, v);
    st_build(tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, v);
    st[pos] = st[pos * 2] + st[pos * 2 + 1];
    st_sz[pos] = st_sz[pos * 2] + st_sz[pos * 2 + 1];
}

// x <- cx + d
void st_modify(int tl, int tr, int pos, int left, int right, double c, double d){
    if(tr < left || right < tl){
        return;
    }
    if(tl == tr){
        st[pos] = lazy_linear[pos] * st[pos] + lazy_const[pos];
        st[pos] = c * st[pos] + d;
        lazy_linear[pos] = 1;
        lazy_const[pos] = 0;
        return;
    }
    if(left <= tl && tr <= right){
        // upd lazy
        lazy_linear[pos] *= c;
        lazy_const[pos] = lazy_const[pos] * c + d;
        // propogate
        lazy_linear[pos * 2] *= lazy_linear[pos];
        lazy_const[pos * 2] = lazy_const[pos * 2] * lazy_linear[pos] + lazy_const[pos];
        lazy_linear[pos * 2 + 1] *= lazy_linear[pos];
        lazy_const[pos * 2 + 1] = lazy_const[pos * 2 + 1] * lazy_linear[pos] + lazy_const[pos];
        // upd sum
        st[pos] = st[pos] * lazy_linear[pos] + lazy_const[pos] * st_sz[pos];
        lazy_linear[pos] = 1;
        lazy_const[pos] = 0;
        return;
    }
    // propogate
    lazy_linear[pos * 2] *= lazy_linear[pos];
    lazy_const[pos * 2] = lazy_const[pos * 2] * lazy_linear[pos] + lazy_const[pos];
    lazy_linear[pos * 2 + 1] *= lazy_linear[pos];
    lazy_const[pos * 2 + 1] = lazy_const[pos * 2 + 1] * lazy_linear[pos] + lazy_const[pos];
    lazy_linear[pos] = 1;
    lazy_const[pos] = 0;
    st_modify(tl, tl + (tr - tl) / 2, pos * 2, left, right, c, d);
    st_modify(tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right, c, d);
    assert(lazy_linear[pos * 2 + 1] == 1 && lazy_linear[pos * 2] == 1 && lazy_const[pos * 2 + 1] == 0 && lazy_const[pos * 2] == 0);
    st[pos] = st[pos * 2] + st[pos * 2 + 1];
}

double st_sum(int tl, int tr, int pos, int left, int right){
    if(tr < left || right < tl){
        if(tl < tr){
            // propogate
            lazy_linear[pos * 2] *= lazy_linear[pos];
            lazy_const[pos * 2] = lazy_const[pos * 2] * lazy_linear[pos] + lazy_const[pos];
            lazy_linear[pos * 2 + 1] *= lazy_linear[pos];
            lazy_const[pos * 2 + 1] = lazy_const[pos * 2 + 1] * lazy_linear[pos] + lazy_const[pos];
            // upd sum
            st[pos] = st[pos] * lazy_linear[pos] + lazy_const[pos] * st_sz[pos];
            lazy_linear[pos] = 1;
            lazy_const[pos] = 0;
        }
        else{
            st[pos] = lazy_linear[pos] * st[pos] + lazy_const[pos];
            lazy_linear[pos] = 1;
            lazy_const[pos] = 0;
        }
        return 0;
    }
    if(tl == tr){
        st[pos] = lazy_linear[pos] * st[pos] + lazy_const[pos];
        lazy_linear[pos] = 1;
        lazy_const[pos] = 0;
        return st[pos];
    }
    if(left <= tl && tr <= right){
        // propogate
        lazy_linear[pos * 2] *= lazy_linear[pos];
        lazy_const[pos * 2] = lazy_const[pos * 2] * lazy_linear[pos] + lazy_const[pos];
        lazy_linear[pos * 2 + 1] *= lazy_linear[pos];
        lazy_const[pos * 2 + 1] = lazy_const[pos * 2 + 1] * lazy_linear[pos] + lazy_const[pos];
        // upd sum
        st[pos] = st[pos] * lazy_linear[pos] + lazy_const[pos] * st_sz[pos];
        lazy_linear[pos] = 1;
        lazy_const[pos] = 0;
        return st[pos];
    }
    // propogate
    lazy_linear[pos * 2] *= lazy_linear[pos];
    lazy_const[pos * 2] = lazy_const[pos * 2] * lazy_linear[pos] + lazy_const[pos];
    lazy_linear[pos * 2 + 1] *= lazy_linear[pos];
    lazy_const[pos * 2 + 1] = lazy_const[pos * 2 + 1] * lazy_linear[pos] + lazy_const[pos];
    lazy_linear[pos] = 1;
    lazy_const[pos] = 0;
    double x = st_sum(tl, tl + (tr - tl) / 2, pos * 2, left, right);
    double y = st_sum(tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    // assert(lazy_linear[pos * 2 + 1] == 1 && lazy_linear[pos * 2] == 1 && lazy_const[pos * 2 + 1] == 0 && lazy_const[pos * 2] == 0);
    st[pos] = st[pos * 2] + st[pos * 2 + 1];
    return x + y;
}

void solve(){
    int n, q;
    cin >> n >> q;
    st.resize(4*n);
    lazy_linear.resize(4*n);
    lazy_const.resize(4*n);
    st_sz.resize(4*n);
    fill(lazy_linear.begin(), lazy_linear.end(), 1);
    fill(lazy_const.begin(), lazy_const.end(), 0);
    vd v(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = (double) x;
    }
    st_build(0, n-1, 1, v);
    debug(st, lazy_const, lazy_linear, st_sz);
    while(q--){
        debug(st, lazy_const, lazy_linear, st_sz);
        int t;
        cin >> t;
        if(t == 1){
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--;r1--;l2--;r2--;
            double s1 = st_sum(0, n-1, 1, l1, r1);
            double s2 = st_sum(0, n-1, 1, l2, r2);
            int sz1 = r1 - l1 + 1, sz2 = r2 - l2 + 1;
            debug(0, n-1, 1, l1, r1, 1.0 * (sz1 - 1) / sz1, 1.0 / sz1 * s2 / sz2);
            debug(0, n-1, 1, l2, r2, 1.0 * (sz2 - 1) / sz2, 1.0 / sz2 * s1 / sz1);
            st_modify(0, n-1, 1, l1, r1, 1.0 * (sz1 - 1) / sz1, 1.0 / sz1 * s2 / sz2);
            st_modify(0, n-1, 1, l2, r2, 1.0 * (sz2 - 1) / sz2, 1.0 / sz2 * s1 / sz1);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;r--;
            double res = st_sum(0, n-1, 1, l, r);
            cout << res << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10);
    solve();
    return 0;
}