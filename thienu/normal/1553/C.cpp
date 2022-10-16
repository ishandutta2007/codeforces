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
    string s;
    cin >> s;
    vi maxd(11);
    vi mind(11);
    for(int i = 0; i < 10; i++){
        int w = (i & 1) ? -1 : 1;
        if(s[i] == '1'){
            maxd[i+1] = maxd[i] + w;
            mind[i+1] = mind[i] + w;
        }else if(s[i] == '?'){
            maxd[i+1] = maxd[i] + max(0, w);
            mind[i+1] = mind[i] + min(0, w);
        }else{
            maxd[i+1] = maxd[i];
            mind[i+1] = mind[i];
        }
    }
    debug(maxd, mind);
    for(int i = 1; i <= 9; i++){
        int left = 10-i;
        int maxp = left / 2;
        int maxm = (left+1) / 2;
        if(-mind[i] > maxp || maxd[i] > maxm){
            cout << i << endl;
            return;
        }
    }
    cout << 10 << endl;
    
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