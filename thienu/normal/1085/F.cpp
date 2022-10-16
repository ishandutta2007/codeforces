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

int wins_to(int type){
    return (type + 2) % 3;
}

int loses_to(int type){
    return (type + 1) % 3;
}

// sum st
void st_set(vi &st, int tl, int tr, int pos, int idx, int val){
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

// sum st
int st_sum(vi &st, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left){
        return 0;
    }
    if(left <= tl && tr <= right){
        return st[pos];
    }
    return st_sum(st, tl, tl + (tr - tl) / 2, pos * 2, left, right)
             + st_sum(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
}

void solve_query(int n, vi &type, vector<set<int>> &positions, vvi &st){
    int ans = 0;
    for(int t = 0; t < 3; t++){
        if(positions[t].empty()){
            continue;
        }
        if(positions[loses_to(t)].empty()){
            ans += positions[t].size();
            continue;
        }
        if(positions[wins_to(t)].empty()){
            continue;
        }
        int impossible = 0;
        int first_loss = *positions[loses_to(t)].begin();
        int first_win = *positions[wins_to(t)].begin();
        if(first_loss < first_win){
            impossible += st_sum(st[t], 0, n-1, 1, first_loss, first_win);
        }
        int last_win = *prev(positions[wins_to(t)].end());
        int last_loss = *prev(positions[loses_to(t)].end());
        if(last_win < last_loss){
            impossible += st_sum(st[t], 0, n-1, 1, last_win, last_loss);
        }
        ans += positions[t].size() - impossible;
    }
    cout << ans << endl;
}

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi type(n);
    vector<set<int>> positions(3);
    vvi st(3, vi(4 * n));
    for(int i = 0; i < n; i++){
        type[i] = (s[i] == 'R' ? 0 : (s[i] == 'P' ? 1 : 2));
        positions[type[i]].insert(i);
        st_set(st[type[i]], 0, n-1, 1, i, 1);
    }
    solve_query(n, type, positions, st);
    while(q--){
        int idx;
        char c;
        cin >> idx >> c;
        idx--;
        int new_type = (c == 'R' ? 0 : (c == 'P' ? 1 : 2));
        positions[type[idx]].erase(idx);
        st_set(st[type[idx]], 0, n-1, 1, idx, 0);
        
        type[idx] = new_type;
        positions[type[idx]].insert(idx);
        st_set(st[type[idx]], 0, n-1, 1, idx, 1);
        solve_query(n, type, positions, st);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}