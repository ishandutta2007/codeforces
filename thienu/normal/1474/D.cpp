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
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vi left(n-1);
    vi right(n-1);

    // populate left
    left[0] = v[0];
    for(int i = 1; i < n-1; i++){
        if(left[i-1] == -1){
            left[i] = -1;
        }
        else{
            left[i] = v[i] - left[i-1];
            if(left[i] < 0) left[i] = -1;
        }
    }

    // populate right
    right[n-2] = v[n-1];
    for(int i = n-3; i >= 0; i--){
        if(right[i+1] == -1){
            right[i] = -1;
        }
        else{
            right[i] = v[i+1] - right[i+1];
            if(right[i] < 0) right[i] = -1;
        }
    }

    debug(left, right);

    if(left[n-2] == v[n-1] || right[0] == v[0]){
        cout << "YES" << endl;
        return;
    }

    for(int i = 0; i + 1 < n; i++){
        // swap i and i+1
        int l = (i-1 >= 0 ? left[i-1] : 0);
        int r = (i+1 < n-1 ? right[i+1] : 0);
        if(l == -1 || r == -1) continue;
        int ldelta = v[i+1] - l;
        int rdelta = v[i] - r;
        debug(i, l, r, ldelta, rdelta);
        if(ldelta >= 0 && ldelta == rdelta){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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