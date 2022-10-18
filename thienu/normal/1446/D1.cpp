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

const int F = 2e5 + 5;
const int G = 4e5 + 10;

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x--;
        v[i] = x;
    }
    int m = min(n, 100);
    vvi cnt(n+1, vi(m));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(v[i-1] == j){
                cnt[i][j] = cnt[i-1][j] + 1;
            }
            else{
                cnt[i][j] = cnt[i-1][j];
            }
        }
    }
    debug(cnt);
    int maxi = -1;
    vi pts;
    for(int i = 0; i < m; i++){
        if(cnt[n][i] > maxi){
            pts.clear();
            pts.push_back(i);
            maxi = cnt[n][i];
        }
        else if(cnt[n][i] == maxi){
            pts.push_back(i);
        }
    }
    debug(maxi, pts);
    if(pts.size() >= 2){
        cout << n << endl;
        return;
    }
    
    int mi = pts[0];
    int ans = 0;
    for(int cand = 0; cand < m; cand++){
        if(cand == mi) continue;
        vi first(G, -2);
        int delta = 0;
        first[delta+F] = -1;
        for(int i = 0; i < n; i++){
            if(v[i] == cand) delta++;
            else if(v[i] == mi) delta--;
            if(first[delta+F] != -2){
                ans = max(ans, i-first[delta+F]);
            }
            else{
                first[delta+F] = i;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}