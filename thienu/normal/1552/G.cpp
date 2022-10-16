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

const int K = 10;
const int N = 40;

// ll sorts[K];
// ll pref[K+1];
// ll fill_one[K][N+1];
vll sorts(K);
vll pref(K+1);
vvll fill_one(K, vll(N+1));
vll shared(K);
vll unchanged(K);
vll new_bits(K);

int n, k;
bool ok = true;

void find(int i, ll cur){
    if(i == k){
        // debug(cur);
        // if((cur & 0b111) == 0b101){
        //     debug(cur);
        // }
        // debug(cur);
        if(cur != 0 && __builtin_popcountll(cur) + __builtin_ctzll(cur) != n){
            ok = false;
        }
        return;
    }
    int x = __builtin_popcountll(new_bits[i]);
    int y = __builtin_popcountll(shared[i] & cur);
    ll base = unchanged[i] & cur;
    for(int j = y; j <= x+y; j++){
        // debug(fill_one[i][j], i, j, x, y);
        ll out = base | (fill_one[i][j]);
        find(i+1, out);
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int q;
        cin >> q;
        ll s = 0;
        for(int j = 0; j < q; j++){
            int x;
            cin >> x;
            x--;
            s |= (1LL << x);
        }
        sorts[i] = s;
    }
    pref[0] = 0;
    for(int i = 1; i <= k; i++){
        pref[i] = pref[i-1] | sorts[i-1];
    }
    for(int i = 0; i < k; i++){
        shared[i] = pref[i] & sorts[i];
        unchanged[i] = pref[i] & (~shared[i]);
        new_bits[i] = sorts[i] & (~shared[i]);
        assert((new_bits[i] | unchanged[i] | shared[i]) == pref[i+1]);
        debug(i, shared[i], unchanged[i], new_bits[i]);
        ll add = new_bits[i] | shared[i];
        debug(i, add);
        vi indices;
        for(int i = 0; i < n; i++){
            if((add >> i) & 1) indices.push_back(i);
        }
        int ptr = indices.size()-1;
        fill_one[i][0] = 0;
        for(int j = 1; j <= indices.size(); j++){
            fill_one[i][j] = fill_one[i][j-1] | (1LL << indices[ptr]);
            ptr--;
        }
    }
    debug(fill_one);

    debug(sorts, pref);

    if(n == 1){
        cout << "ACCEPTED" << endl;
        return;
    }
    if(pref[k] != (1LL<<n)-1){
        cout << "REJECTED" << endl;
        return;
    }

    find(0, 0);
    if(ok){
        cout << "ACCEPTED" << endl;
    }else{
        cout << "REJECTED" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}