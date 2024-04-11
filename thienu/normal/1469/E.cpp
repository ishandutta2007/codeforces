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

const int T = 20;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        s[i] = (s[i] == '0' ? '1' : '0');
    }
    debug(s);
    set<int> occ;
    int one_idx = -1;
    int t = min(T, k);
    for(int i = 0; i < k-t; i++){
        if(s[i] == '1') one_idx = i;
    }
    for(int i = 0; i+k <= n; i++){
        debug(i, one_idx);
        if(one_idx < i){
            int cur = 0;
            for(int j = i+k-t; j < i+k; j++){
                cur <<= 1;
                cur += s[j]-'0';
            }
            debug(i, cur);
            occ.insert(cur);
        }
        // shift
        debug(i, i+k-t);
        if(s[i+k-t] == '1') one_idx = i+k-t;
    }

    debug(occ);
    
    int ans = -1;
    for(auto it = occ.begin(); it != occ.end(); it++){
        if(*it == ans + 1){
            ans = *it;
        }else{
            break;
        }
    }
    ans++;
    if(k <= T && ans >= (1 << k)){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        string s;
        for(int i = 0; i < k; i++){
            s += ('0' + (ans & 1));
            ans >>= 1;
        }
        reverse(s.begin(), s.end());
        for(char c : s){
            cout << c;
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