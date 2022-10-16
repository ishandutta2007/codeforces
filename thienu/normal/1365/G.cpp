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

void solve(){
    int n;
    cin >> n;
    vi mask;
    for(int i = 0; i < (1 << 13); i++){
        if(__builtin_popcount(i) == 6) mask.push_back(i);
    }
    debug(mask);
    vll res(13);
    for(int i = 0; i < 13; i++){
        vi query;
        for(int j = 0; j < n; j++){
            if((mask[j] >> i) & 1){
                query.push_back(j);
            }
        }
        if(query.empty()){
            res[i] = 0;
        }
        else{
            cout << "? " << query.size();
            for(int j : query){
                cout << ' ' << j+1;
            }
            cout << endl;
            ll x;
            cin >> x;
            res[i] = x;
        }
    }
    cout << '!';
    for(int i = 0; i < n; i++){
        ll ans = 0;
        for(int j = 0; j < 13; j++){
            if(((mask[i] >> j) & 1) ^ 1){
                ans |= res[j];
            }
        }
        cout << ' ' << ans;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}