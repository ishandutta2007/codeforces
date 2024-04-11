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

// sum st
void st_set(vll &st, int tl, int tr, int pos, int idx, ll val){
    if(tl == tr){
        st[pos] = val;
        return;
    }
    if(idx <= tl + (tr - tl) / 2){
        st_set(st, tl, tl + (tr - tl) / 2, pos * 2, idx, val);
    }
    else{
        st_set(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, idx, val);
    }
    st[pos] = st[pos * 2] + st[pos * 2 + 1];
}

ll st_sum(vll &st, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left){
        return 0;
    }
    if(left <= tl && tr <= right){
        return st[pos];
    }
    return st_sum(st, tl, tl + (tr - tl) / 2, pos * 2, left, right)
         + st_sum(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
}

struct PrefixStack{
    int n;
    int cur_size;
    vll st;
    PrefixStack(int _n){
        n = _n;
        cur_size = 0;
        st.resize(4 * n);
    }

    void push(ll x){
        assert(cur_size < n);
        st_set(st, 0, n-1, 1, cur_size, x);
        cur_size++;
    }

    void pop(){
        assert(cur_size > 0);
        cur_size--;
    }

    ll sum_top(int p){
        assert(cur_size >= p);
        if(p == 0) return 0;
        return st_sum(st, 0, n-1, 1, cur_size - p, cur_size - 1);
    }

    ll topk_idx(int k){
        return st_sum(st, 0, n-1, 1, cur_size - k - 1, cur_size - k - 1);
    }
};

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vll ans(n);
    PrefixStack above(n), below(n);
    // build stack for i=0
    for(int i = n-1; i >= 1; i--){
        if(s[i] == 'D'){
            above.push(i);
        }
    }
    if(s[0] == 'D'){
        ans[0] = 1;
    }
    else{
        if(above.cur_size){
            ans[0] = 2 * above.topk_idx(0) + 1;
        }
        else{
            ans[0] = n;
        }
    }
    for(int i = 1; i < n; i++){
        // update stacks
        if(s[i] == 'D'){
            above.pop();
        }
        if(s[i-1] == 'U'){
            below.push(i-1);
        }
        int sa = above.cur_size, sb = below.cur_size;
        debug(i, sa, sb);
        ll num_above, num_below;
        bool finish_up;
        if(s[i] == 'U'){
            if(sa > sb){
                num_above = sb+1;
                num_below = sb;
                finish_up = 0;
            }
            else{
                num_above = sa;
                num_below = sa;
                finish_up = 1;
            }
        }
        else{
            if(sb > sa){
                num_above = sa;
                num_below = sa+1;
                finish_up = 1;
            }
            else{
                num_above = sb;
                num_below = sb;
                finish_up = 0;
            }
        }
        ll extra;
        if(finish_up){
            extra = n - i;
        }
        else{
            extra = i + 1;
        }
        debug(num_above, num_below, extra);
        ans[i] = 2LL * ((num_below - num_above) * i + above.sum_top(num_above) - below.sum_top(num_below)) + extra;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}