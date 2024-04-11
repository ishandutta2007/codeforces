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
    set<pii> one;
    set<pii> two;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i + j) & 1){
                one.insert({i, j});
            }
            else{
                two.insert({i, j});
            }
        }
    }
    for(int i = 0; i < n * n; i++){
        int c;
        cin >> c;
        if(c == 1){
            if(two.empty()){
                pii x = *one.begin();
                one.erase(one.begin());
                cout << 3 << ' ' << x.first << ' ' << x.second << endl;
            }
            else{
                pii x = *two.begin();
                two.erase(two.begin());
                cout << 2 << ' ' << x.first << ' ' << x.second << endl;
            }
        }
        else if(c == 2){
            if(one.empty()){
                pii x = *two.begin();
                two.erase(two.begin());
                cout << 3 << ' ' << x.first << ' ' << x.second << endl;
            }
            else{
                pii x = *one.begin();
                one.erase(one.begin());
                cout << 1 << ' ' << x.first << ' ' << x.second << endl;
            }
        }
        else{
            if(one.empty()){
                pii x = *two.begin();
                two.erase(two.begin());
                cout << 2 << ' ' << x.first << ' ' << x.second << endl;
            }
            else{
                pii x = *one.begin();
                one.erase(one.begin());
                cout << 1 << ' ' << x.first << ' ' << x.second << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}