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
    int n, m, ka, kb;
    cin >> n >> m >> ka >> kb;
    vi a(ka); // 0..n-1
    vi b(kb); // n..n+m-1
    for(int i = 0; i < ka; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < kb; i++){
        cin >> b[i];
        b[i]--;
    }
    if(ka >= m || kb >= n){
        cout << "NO" << endl;
        return;
    }
    while(ka < m-1){
        ka++;
        a.push_back(0);
    }
    while(kb < n-1){
        kb++;
        b.push_back(n);
    }
    vi degree(n+m, 1);
    for(int i : a){
        degree[i]++;
    }
    for(int i : b){
        degree[i]++;
    }
    set<int> s;
    for(int i = 0; i < n+m; i++){
        if(degree[i] == 1) s.insert(i);
    }
    vpii edges;
    int pa = 0, pb = 0;
    while(pa < ka || pb < kb){
        int x = *s.begin();
        s.erase(s.begin());
        if(x < n){
            int par = b[pb];
            edges.push_back({x, par});
            pb++;
            degree[par]--;
            if(degree[par] == 1) s.insert(par);
        }
        else{
            int par = a[pa];
            edges.push_back({x, par});
            pa++;
            degree[par]--;
            if(degree[par] == 1) s.insert(par);
        }
    }
    debug(degree);
    int x = *s.begin();
    s.erase(s.begin());
    edges.push_back({x, n+m-1});
    cout << "Yes" << endl;
    for(pii p : edges){
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}