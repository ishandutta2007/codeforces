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
    int k;
    cin >> n >> k;
    vvi graph(n, vi(n, -1));
    ll sum = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int x;
            cin >> x;
            graph[i][j] = x;
            graph[j][i] = x;
            if(x != -1){
                sum += x;
            }
        }
    }
    if(k == 1){
        cout << sum * 2 / n << endl;
    }
    else if(k >= 3){
        cout << sum * 2 / n << endl;
    }
    else{
        // k == 2
        ll ans_sum = 0;
        ll num_pairs = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            ll weight_sum = 0;
            for(int j = 0; j < n; j++){
                if(graph[i][j] != -1){
                    weight_sum += graph[i][j];
                    cnt++;
                }
            }
            ans_sum += weight_sum * (cnt-1);
            num_pairs += cnt * (cnt-1) / 2;
        }
        cout << ans_sum / num_pairs << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}