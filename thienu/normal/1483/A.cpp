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
    int n, m;
    cin >> n >> m;
    vvi days(m);
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int y;
            cin >> y;
            days[i].push_back(y-1);
        }
    }

    if(m == 1){
        cout << "YES" << endl;
        cout << days[0][0]+1 << endl;
        return;
    }
    if(n == 1){
        cout << "NO" << endl;
        return;
    }

    vi ans(m, -1);
    vi freq(n);
    for(int i = 0; i < m; i++){
        if(days[i].size() == 1){
            freq[days[i][0]]++;
            ans[i] = days[i][0];
        }
    }
    
    debug(ans, freq);
    for(int i = 0; i < n; i++){
        if(freq[i] > (m + 1) / 2){
            cout << "NO" << endl;
            return;
        }
    }
    
    for(int i = 0; i < m; i++){
        if(ans[i] == -1){
            if(freq[days[i][0]] + 1 > (m + 1) / 2){
                freq[days[i][1]]++;
                ans[i] = days[i][1];
            }
            else{
                freq[days[i][0]]++;
                ans[i] = days[i][0];
            }
        }
    }
    debug(freq);

    cout << "YES" << endl;
    for(int i = 0; i < m; i++){
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
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