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

int get_msd(int a){
    int x = 0;
    while(a){
        a >>= 1;
        x++;
    }
    return x;
}

int ans(vi v){
    // debug(v);
    int n = v.size();
    if(n <= 2) return n;
    // set<int> msd;
    vi msd(31);
    for(int i = 0; i < n; i++){
        msd[get_msd(v[i])] = 1;
    }
    int maxi = 0;
    vi msd_below(31);
    for(int i = 1; i <= 30; i++){
        msd_below[i] = max(msd_below[i-1], msd[i-1]);
    }
    vi msd_above(31);
    for(int i = 29; i >= 0; i--){
        msd_above[i] = msd_above[i+1] + msd[i+1];
    }
    debug(msd, msd_below, msd_above);
    for(int i = 0; i <= 30; i++){
        // debug(i);
        // remove all but with msd i
        vi u;
        for(int j = 0; j < n; j++){
            if(i == 0){
                if(v[j] == 0) u.push_back(v[j]);
            }
            else{
                if(get_msd(v[j]) == i){
                    debug(v[j], i, ((1 << (i-1)) - 1) & v[j]);
                    u.push_back(((1 << (i-1)) - 1) & v[j]);
                }
            }
        }
        maxi = max(maxi, ans(u) + msd_below[i] + msd_above[i]);
    }
    debug(v, maxi);
    return maxi;
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << n - ans(v) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}