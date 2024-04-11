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

int mini, maxi;

void constraint(int m, int c, int lo, int hi){
    if(m > 0){
        mini = max(mini, (lo-c)/m);
        maxi = min(maxi, (hi-c)/m);
    }else{
        mini = max(mini, (hi-c)/m);
        maxi = min(maxi, (lo-c)/m);
    }
}

void ca(int awin, int bwin, set<int> &ans){
    // int awin, bwin;
    // cin >> awin >> bwin;
    int n = awin + bwin;
    int aserve = (n+1)/2;
    int bserve = n - aserve;
    debug(awin, bwin, aserve, bserve);
    mini = -1e9;
    maxi = 1e9;

    constraint(1, 0, 0, min(aserve, bwin));
    constraint(-1, aserve, 0, min(awin, aserve));
    constraint(-1, bwin, 0, min(bwin, aserve));
    constraint(1, bserve-bwin, 0, min(awin, bserve));
    debug(mini, maxi);

    if(maxi < mini) return;

    for(int i = mini; i <= maxi; i++){
        ans.insert(2 * i + bserve - bwin);
    }
}

void solve(){
    int a, b;
    cin >> a >> b;
    set<int> ans;
    ca(a, b, ans);
    ca(b, a, ans);
    cout << ans.size() << endl;
    for(int i : ans) cout << i << ' ';
    cout << endl;
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