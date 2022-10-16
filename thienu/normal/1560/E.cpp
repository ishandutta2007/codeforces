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

int A = 26;

void solve(){
    string t;
    cin >> t;
    int n = t.size();
    vi used(A);
    vi order;
    for(int i = n-1; i >= 0; i--){
        if(used[t[i]-'a']) continue;
        order.push_back(t[i]-'a');
        used[t[i]-'a'] = 1;
    }
    reverse(order.begin(), order.end());
    debug(order);
    vi times(A);
    int x = 0;
    for(int i : order){
        times[i] = ++x;
    }
    debug(times);

    int sz = 0, i;
    for(i = 0; sz < n; i++){
        sz += times[t[i]-'a'];
    }
    debug(i, sz);

    if(sz > n){
        cout << -1 << endl;
        return; 
    }

    // simulate (check)
    string s = t.substr(0, i);
    debug(s);
    string cur = s, out = s;
    for(int i : order){
        string ns = "";
        for(char c : cur){
            if(c-'a' != i){
                ns+=c;
            }
        }
        out += ns;
        cur = ns;
    }
    debug(out);
    if(t == out){
        cout << s << ' ';
        for(int i : order){
            cout << (char)(i+'a');
        }
        cout << endl;
    }else{
        cout << -1 << endl;
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