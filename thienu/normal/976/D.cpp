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
    int m;
    cin >> m;
    vi d(m);
    for(int i = 0; i < m; i++){
        cin >> d[i];
    }
    int n = d[m-1] + 1;
    
    vpii ans;
    int sz = n;
    bool state = true;
    for(int cur = 0; cur < n; cur++){
        debug(cur, sz, d);
        if(state && d[0] == 0){
            state = false;
            d.pop_back();
        }
        else if(!state && d[d.size()-1] + 1 == sz) state = true;
        if(state){
            if(d[0] == 0){
                d.erase(d.begin());
            }
            for(int &i : d){
                i--;
            }
            for(int i = cur+1; i < n; i++){
                ans.push_back({cur, i});
            }
        }else{
            
        }
        sz--;
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first+1 << ' ' << p.second+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}