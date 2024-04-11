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

int INF = 1e9 + 7;

void st_add(vi &minst, vi &maxst, vi &lazy, int tl, int tr, int pos, int left, int right, int add){
    if(right < tl || tr < left){
        return;
    }
    if(left <= tl && tr <= right){
        // lazy add
        lazy[pos] += add;
        return;
    }
    // propogate
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;
    st_add(minst, maxst, lazy, tl, tl + (tr - tl) / 2, pos * 2, left, right, add);
    st_add(minst, maxst, lazy, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right, add);
    // st[pos] = calc(st[pos * 2], lazy[pos * 2], tl, tl + (tr - tl) / 2)
    //         + calc(st[pos * 2 + 1], lazy[pos * 2 + 1], tl + (tr - tl) / 2 + 1, tr);
    minst[pos] = min(minst[pos * 2] + lazy[pos * 2], minst[pos * 2 + 1] + lazy[pos * 2 + 1]);
    maxst[pos] = max(maxst[pos * 2] + lazy[pos * 2], maxst[pos * 2 + 1] + lazy[pos * 2 + 1]);
}

int st_min(vi &minst, vi &maxst, vi &lazy, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left){
        return INF;
    }
    if(tl == tr){
        minst[pos] += lazy[pos];
        maxst[pos] += lazy[pos];
        lazy[pos] = 0;
        return minst[pos];
    }
    // propogate
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;
    // st[pos] = calc(st[pos * 2], lazy[pos * 2], tl, tl + (tr - tl) / 2)
    //         + calc(st[pos * 2 + 1], lazy[pos * 2 + 1], tl + (tr - tl) / 2 + 1, tr);
    minst[pos] = min(minst[pos * 2] + lazy[pos * 2], minst[pos * 2 + 1] + lazy[pos * 2 + 1]);
    maxst[pos] = max(maxst[pos * 2] + lazy[pos * 2], maxst[pos * 2 + 1] + lazy[pos * 2 + 1]);
    if(left <= tl && tr <= right){
        return minst[pos];
    }
    int a1 = st_min(minst, maxst, lazy, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    int a2 = st_min(minst, maxst, lazy, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    return min(a1, a2);
}

int st_max(vi &minst, vi &maxst, vi &lazy, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left){
        return -INF;
    }
    if(tl == tr){
        debug(tl, tr, pos, maxst[pos], lazy[pos]);
        minst[pos] += lazy[pos];
        maxst[pos] += lazy[pos];
        lazy[pos] = 0;
        return maxst[pos];
    }
    // propogate
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;
    // st[pos] = calc(st[pos * 2], lazy[pos * 2], tl, tl + (tr - tl) / 2)
    //         + calc(st[pos * 2 + 1], lazy[pos * 2 + 1], tl + (tr - tl) / 2 + 1, tr);
    minst[pos] = min(minst[pos * 2] + lazy[pos * 2], minst[pos * 2 + 1] + lazy[pos * 2 + 1]);
    maxst[pos] = max(maxst[pos * 2] + lazy[pos * 2], maxst[pos * 2 + 1] + lazy[pos * 2 + 1]);
    if(left <= tl && tr <= right){
        return maxst[pos];
    }
    int a1 = st_max(minst, maxst, lazy, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    int a2 = st_max(minst, maxst, lazy, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    return max(a1, a2);
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }
    vvi lookup(n);
    for(int i = 0; i < n; i++){
        lookup[v[i]].push_back(i);
    }
    vi left_ans(n);
    {
        // prefix sums, >= i -> +1, < i -> -1
        // [i, j] is p[j+1] - p[i]
        vi minst(4 * (n+1)), maxst(4 * (n+1)), lazy(4 * (n+1));
        // intialize i=0
        for(int i = 0; i < n; i++){
            st_add(minst, maxst, lazy, 0, n, 1, i+1, n, 1);
        }
        
        // answer for i=0
        for(int j : lookup[0]){
            left_ans[j] = (st_max(minst, maxst, lazy, 0, n, 1, j+1, n) - st_min(minst, maxst, lazy, 0, n, 1, 0, j)) / 2;
        }
        for(int i = 1; i < n; i++){
            // update i
            for(int j : lookup[i-1]){
                // switch from +1 to -1
                debug(j);
                st_add(minst, maxst, lazy, 0, n, 1, j+1, n, -2);
            }
            // answer for i
            for(int j : lookup[i]){
                int maxi = st_max(minst, maxst, lazy, 0, n, 1, j+1, n);
                int mini = st_min(minst, maxst, lazy, 0, n, 1, 0, j);
                debug(mini, maxi);
                left_ans[j] = (maxi - mini) / 2;
            }
        }
    }
    debug(left_ans);
    vi right_ans(n);
    {
        // prefix sums, <= i -> +1, > i -> -1
        // [i, j] is p[j+1] - p[i]
        vi minst(4 * (n+1)), maxst(4 * (n+1)), lazy(4 * (n+1));
        // intialize i=0
        for(int i = 0; i < n; i++){
            int val = (v[i] == 0 ? 1 : -1);
            st_add(minst, maxst, lazy, 0, n, 1, i+1, n, val);
        }
        
        // answer for i=0
        for(int j : lookup[0]){
            right_ans[j] = (st_max(minst, maxst, lazy, 0, n, 1, j+1, n) - st_min(minst, maxst, lazy, 0, n, 1, 0, j) - 1) / 2;
        }
        for(int i = 1; i < n; i++){
            // update i
            for(int j : lookup[i]){
                // switch from -1 to +1
                debug(j);
                st_add(minst, maxst, lazy, 0, n, 1, j+1, n, 2);
            }
            // answer for i
            for(int j : lookup[i]){
                int maxi = st_max(minst, maxst, lazy, 0, n, 1, j+1, n);
                int mini = st_min(minst, maxst, lazy, 0, n, 1, 0, j);
                debug(mini, maxi);
                right_ans[j] = (maxi - mini - 1) / 2;
            }
        }
    }
    debug(right_ans);
    for(int i = 0; i < n; i++){
        cout << max(left_ans[i], right_ans[i]) << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}