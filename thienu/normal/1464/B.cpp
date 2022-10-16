#include <bits/stdc++.h>



#define int long long

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

#undef int
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

#define int long long

ll INF = 2e18 + 5;

void solve(){
    string s;
    int x, y;
    cin >> s >> x >> y;
    int n = s.length();

    // pref: before
    // suf: after
    vi pref0(n), suf0(n), pref1(n), suf1(n);
    for(int i = 1; i < n; i++){
        pref0[i] = pref0[i-1] + (s[i-1] == '0');
        pref1[i] = pref1[i-1] + (s[i-1] == '1');
    }
    for(int i = n-2; i >= 0; i--){
        suf0[i] = suf0[i+1] + (s[i+1] == '0');
        suf1[i] = suf1[i+1] + (s[i+1] == '1');
    }
    debug(pref0, pref1, suf0, suf1);

    vi cost0(n), cost1(n);

    for(int i = 0; i < n; i++){
        cost0[i] = pref1[i] * y + suf1[i] * x;
        cost1[i] = pref0[i] * x + suf0[i] * y;
    }

    debug(cost0, cost1);

    ll initial_cost = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') initial_cost += cost1[i];
        else if(s[i] == '0') initial_cost += cost0[i];
    }

    initial_cost /= 2;

    debug(initial_cost);


    vi questions;
    for(int i = 0; i < n; i++){
        if(s[i] == '?') questions.push_back(i);
    }
    int m = questions.size();

    if(m == 0){
        cout << initial_cost << endl;
        return;
    }

    ll best = INF;
    // slice 0-1
    ll running_cost = 0;
    // set all 1s
    for(int i = 0; i < m; i++){
        running_cost += cost1[questions[i]];
    }
    debug(running_cost);
    for(int i = 0; i < m; i++){
        // i is index of last 0
        // shift running cost
        running_cost += cost0[questions[i]];
        running_cost -= cost1[questions[i]];
        debug(running_cost, x * (i+1) * (m-i-1));
        ll cost = initial_cost + running_cost + (ll) x * (i+1) * (m-i-1);
        debug(cost);
        best = min(best, cost);
    }

    // slice 1-0
    running_cost = 0;
    // set all 0s
    for(int i = 0; i < m; i++){
        running_cost += cost0[questions[i]];
    }
    debug(running_cost);
    for(int i = 0; i < m; i++){
        // i is index of last 1
        // shift running cost
        running_cost += cost1[questions[i]];
        running_cost -= cost0[questions[i]];
        debug(running_cost, y * (i+1) * (m-i-1));
        ll cost = initial_cost + running_cost + (ll) y * (i+1) * (m-i-1);
        debug(cost);
        best = min(best, cost);
    }
    

    cout << best << endl;
}

#undef int
int main(){
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}