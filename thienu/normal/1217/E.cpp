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

using vvpii = vector<vpii>;

int INF = 2e9 + 7;
int DIGITS = 9;

int n;

vvpii vst;

void upd(vpii &st, int pos){
    if(st[2 * pos].first < st[2 * pos + 1].first){
        st[pos] = {st[2 * pos].first, min(st[2 * pos].second, st[2 * pos + 1].first)};
    }
    else{
        st[pos] = {st[2 * pos + 1].first, min(st[2 * pos].first, st[2 * pos + 1].second)};
    }
}

void build_st(vpii &st, vi &v, int tl, int tr, int pos){
    if(tl == tr){
        st[pos] = {v[tl], INF};
        return;
    }
    build_st(st, v, tl, tl + (tr - tl) / 2, pos * 2);
    build_st(st, v, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1);
    upd(st, pos);
}

void set_st(vpii &st, int tl, int tr, int pos, int set_pos, int set_value){
    if(set_pos < tl || tr < set_pos) return;
    if(tl == tr){
        st[pos] = {set_value, INF};
        return;
    }
    set_st(st, tl, tl + (tr - tl) / 2, pos * 2, set_pos, set_value);
    set_st(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, set_pos, set_value);
    upd(st, pos);
}

pii min_st(vpii &st, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left){
        return {INF, INF};
    }
    if(left <= tl && tr <= right){
        return st[pos];
    }
    pii a = min_st(st, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    pii b = min_st(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    if(a.first < b.first){
        return {a.first, min(a.second, b.first)};
    }
    else{
        return {b.first, min(b.second, a.first)};
    }
}

void solve(){
    int q;
    cin >> n >> q;
    vi v(n);
    vector<string> v_str(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        string s = to_string(v[i]);
        int digits_to_add = DIGITS - s.size();
        string ns = "";
        for(int i = 0; i < digits_to_add; i++){
            ns += '0';
        }
        ns += s;
        v_str[i] = ns;
    }

    debug(v, v_str);

    vst.resize(DIGITS);
    fill(vst.begin(), vst.end(), vpii(4 * n));

    for(int d = 0; d < DIGITS; d++){
        vi nonzero_d(n);
        for(int i = 0; i < n; i++){
            if(v_str[i][d] != '0'){
                nonzero_d[i] = v[i];
            }
            else{
                nonzero_d[i] = INF;
            }
        }
        build_st(vst[d], nonzero_d, 0, n-1, 1);
    }

    debug(vst[8]);

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int pos, val;
            cin >> pos >> val;
            pos--;
            v[pos] = val;
            string s = to_string(val);
            int digits_to_add = DIGITS - s.size();
            string ns = "";
            for(int i = 0; i < digits_to_add; i++){
                ns += '0';
            }
            ns += s;
            for(int d = 0; d < DIGITS; d++){
                if(ns[d] != '0'){
                    set_st(vst[d], 0, n-1, 1, pos, val);
                }
                else{
                    set_st(vst[d], 0, n-1, 1, pos, INF);
                }
            }
        }
        else{
            int left, right;
            cin >> left >> right;
            left--;
            right--;
            int ans = INF;
            for(int d = 0; d < 9; d++){
                pii p = min_st(vst[d], 0, n-1, 1, left, right);
                if(p.second == INF) continue;
                ans = min(ans, p.first + p.second);
            }
            if(ans == INF){
                cout << -1 << endl;
            }
            else{
                cout << ans << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}