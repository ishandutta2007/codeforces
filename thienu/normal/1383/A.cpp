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
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int find_set(int v, vector<int> &parent){
    if(parent[v] == -1) return -1;
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size){
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a != b){
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            cout << -1 << endl;
            return;
        }
    }

    vector<int> parent(20, -1);
    vector<int> size(20, -1);

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(parent[a[i]-'a'] == -1 && parent[b[i]-'a'] >= 0){
                parent[a[i]-'a'] = b[i]-'a';
                size[find_set(b[i]-'a', parent)]++;
            }
            else if(parent[b[i]-'a'] == -1 && parent[a[i]-'a'] >= 0){
                parent[b[i]-'a'] = a[i]-'a';
                size[find_set(a[i]-'a', parent)]++;
            }
            else if(parent[a[i]-'a'] == -1 && parent[b[i]-'a'] == -1){
                parent[a[i]-'a'] = a[i]-'a';
                parent[b[i]-'a'] = a[i]-'a';
                size[a[i]-'a'] = 2;
            }
            else{
                union_sets(a[i]-'a', b[i]-'a', parent, size);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 20; i++){
        if(find_set(i, parent) == i){
            ans += size[i] - 1;
        }
    }
    debug(parent);
    debug(size);
    cout << ans << endl;
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