#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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

int pow(int a, int b){
    int ans = 1;
    while(b--) ans *= a;
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    bool same = true;
    int last = -1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(last != x){
            v.push_back(x);
        }
        last = x;
    }
    n = v.size();
    debug(v);
    if(k == 1){
        cout << (n == 1 ? 1 : -1) << endl;
        return;
    }
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    cout << (n - 2) / (k - 1) + 1 << endl;
}

// 9 3
// 0 1 2
//     0 1 2
//         0 1 2
//             0 1 2

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