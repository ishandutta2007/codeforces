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
    vpii moves;
    for(int i = (n+3)/2; i < n; i++){
        moves.push_back({i, 1});
    }
    for(int i = 2; i < (n+3)/2; i++){
        moves.push_back({i, n});
    }
    moves.push_back({1, n});

    debug(moves);

    vi state(n);
    for(int i = 0; i < n; i++){
        state[i] = i+1;
    }

    reverse(moves.begin(), moves.end());


    ll ans = 0;
    for(pii p : moves){
        swap(state[p.first - 1], state[p.second - 1]);
        ans += (ll) abs(p.first - p.second) * (ll) abs(p.first - p.second);
    }

    reverse(moves.begin(), moves.end());

    debug(state, ans);

    cout << ans << endl;
    for(int i : state){
        cout << i << " ";
    }
    cout << endl;
    cout << n-1 << endl;
    for(pii p : moves){
        cout << p.first << " " << p.second << endl;
    }
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