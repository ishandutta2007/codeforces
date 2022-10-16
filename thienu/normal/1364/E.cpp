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


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randint(ll a, ll b){
    return a + rng() % (b-a);
}

int log2(int x){
    return 8*sizeof(int) - __builtin_clz(x) - 1;
}

int query(int a, int b){
    cout << "? " << a+1 << ' ' << b+1 << endl;
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
}

void answer(vi &v){
    cout << '!';
    for(int i : v){
        cout << ' ' << i;
    }
    cout << endl;
}

int n, bit;

int get(int idx, vpii &z){
    debug("get", idx, z);
    int ans = 0;
    for(int i = 0; i < bit; i++){
        int mask = (1 << i);
        ans |= (mask & query(idx, (z[i].first == idx) ? z[i].second : z[i].first));
    }
    return ans;
}

void solve(){
    cin >> n;
    bit = log2(n-1)+1;
    debug(bit);
    vpii z(bit, {-1, -1});
    int filled = 0;
    while(filled < bit){
        int a = randint(0, n);
        int b = randint(0, n);
        if(a == b) continue;
        int res = query(a, b);
        for(int i = 0; i < bit; i++){
            if(z[i] != make_pair(-1, -1)) continue;
            if((res >> i) & 1) continue;
            z[i] = {a, b};
            filled++;
            debug(filled);
        }
    }
    debug(z);
    int idx = 0;
    int val = get(0, z);
    if(val == 0) goto done;
    for(int i = 1; i < n; i++){
        debug(i);
        if(query(i, idx) == val){
            idx = i;
            val = get(i, z);
            if(val == 0){
                break;
            }
        }
    }
    done:
    vi ans(n);
    for(int i = 0; i < n; i++){
        if(i == idx){
            ans[i] = 0;
            continue;
        }
        ans[i] = query(idx, i);
    }
    answer(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}