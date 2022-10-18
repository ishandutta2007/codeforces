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
    int l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    vector<pair<pii, int>> edges;
    // values 1 start, 23 end, 2 link, 3..22 are 2^19..2^0
    // build backbone
    int n = 23;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < i; j++){
            edges.push_back({{22-i, 22-j}, 1 << j});
        }
        edges.push_back({{22-i, 23}, 1});
    }
    // debug(edges);
    if(l == 1){
        edges.push_back({{1, 23}, 1});
        int next = 1;
        for(int i = 0; i < 20; i++){
            if(((r-1) >> i) & 1){
                edges.push_back({{1, 22-i}, next});
                next += (1 << i);
            }
        }
    }
    else{
        edges.push_back({{2, 23}, 1});
        int next = 1;
        for(int i = 0; i < 20; i++){
            if(((r-l) >> i) & 1){
                edges.push_back({{2, 22-i}, next});
                next += (1 << i);
            }
        }
        edges.push_back({{1, 2}, l-1});
    }
    debug(edges);

    cout << 23 << " " << edges.size() << endl;
    for(auto p : edges){
        cout << p.first.first << " " << p.first.second << " " << p.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}