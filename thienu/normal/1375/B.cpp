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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if((i == 0 || i == n-1) && (j == 0 || j == m-1)){
                if(v[i][j] > 2){
                    ok = false;
                }
            }
            if((i == 0 || i == n-1) || (j == 0 || j == m-1)){
                if(v[i][j] > 3){
                    ok = false;
                }
            }
            if(v[i][j] > 4){
                ok = false;
            }
        }
    }
    if(!ok){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 || i == n-1) && (j == 0 || j == m-1)){
                cout << 2 << " ";
            }
            else if((i == 0 || i == n-1) || (j == 0 || j == m-1)){
                cout << 3 << " ";
            }
            else{
                cout << 4 << " ";
            }
        }
        cout << endl;
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