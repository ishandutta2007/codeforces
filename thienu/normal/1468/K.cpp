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

pii simulate(string &s, int n, pii &obstacle){
    pii cur = {0, 0};
    for(int i = 0; i < n; i++){
        pii loc;
        switch(s[i]){
            case 'U':
                loc = {cur.first, cur.second + 1};
                break;
            case 'D':
                loc = {cur.first, cur.second - 1};
                break;
            case 'L':
                loc = {cur.first - 1, cur.second};
                break;
            case 'R':
                loc = {cur.first + 1, cur.second};
                break;
        }
        if(loc != obstacle){
            cur = loc;
        }
    }
    return cur;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    pii x = make_pair(1e9, 1e9);

    for(int i = 1; i <= n; i++){
        pii pos = simulate(s, i, x);
        debug(pos);

        pii out = simulate(s, n, pos);
        if(out == make_pair(0, 0)){
            cout << pos.first << " " << pos.second << endl;
            return;
        }
    }
    cout << "0 0" << endl;
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