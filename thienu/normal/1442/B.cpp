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

ll MOD = 998244353;

void build(vi &st, int tl, int tr, int pos){
    if(tl == tr){
        st[pos] = tl;
        return;
    }
    build(st, tl, tl + (tr - tl) / 2, pos * 2);
    build(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1);
}

int get_pos(vi &st, vi &add, int tl, int tr, int pos, int pos_to_get){
    if(tr < pos_to_get || pos_to_get < tl) return 0;
    if(tl == tr){
        st[pos] += add[pos];
        return st[pos];
    }
    add[pos * 2] += add[pos];
    add[pos * 2 + 1] += add[pos];
    add[pos] = 0;
    int a = get_pos(st, add, tl, tl + (tr - tl) / 2, pos * 2, pos_to_get);
    int b = get_pos(st, add, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, pos_to_get);
    return a + b;
}

void add_to(vi &add, int tl, int tr, int pos, int left, int right, int add_by){
    if(tr < left || right < tl) return;
    if(left <= tl && tr <= right){
        add[pos] += add_by;
        return;
    }
    add_to(add, tl, tl + (tr - tl) / 2, pos * 2, left, right, add_by);
    add_to(add, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right, add_by);
}

void solve(){
    int n, k;
    cin >> n >> k;

    vi a(n), b(k), pos(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 0; i < k; i++){
        cin >> b[i];
    }

    // transform to trivial permutation
    for(int i = 0; i < k; i++){
        b[i] = pos[b[i]];
    }

    for(int i = 0; i < n; i++){
        a[i] = i;
    }
    debug(b);

    // segtree of position of each element
    vi st(4 * n);
    vi add(4 * n);
    build(st, 0, n-1, 1);
    // debug(st);
    // add_to(add, 0, n-1, 1, 3, 6, -1);
    // cerr << "get_pos" << get_pos(st, add, 0, n-1, 1, 4);

    set<int> remaining;
    set<int> to_delete;
    for(int i = 0; i < n; i++){
        remaining.insert(i);
    }
    for(int i = 0; i < k; i++){
        to_delete.insert(b[i]);
    }

    ll ans = 1;
    for(int i = 0; i < k; i++){
        // delete next to b[i]
        debug(i, remaining, to_delete);
        to_delete.erase(b[i]);
        int position = get_pos(st, add, 0, n-1, 1, b[i]);
        int left = -1, right = -1;
        if(position > 0 && to_delete.find(*prev(remaining.lower_bound(b[i]))) == to_delete.end()){
            left = *prev(remaining.lower_bound(b[i]));
        }
        if(position < n - i - 1 && to_delete.find(*remaining.upper_bound(b[i])) == to_delete.end()){
            right = *remaining.lower_bound(b[i] + 1);
        }
        debug(i, b[i], position, left, right);

        if(left == -1 && right == -1){
            cout << 0 << endl;
            return;
        }

        if(left != -1 && right != -1) ans = (ans * 2) % MOD;
        if(left == -1) swap(left, right);

        // erase left
        remaining.erase(left);
        add_to(add, 0, n-1, 1, left + 1, n-1, -1);
    }
    cout << ans << endl;
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