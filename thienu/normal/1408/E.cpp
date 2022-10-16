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


int find(int x, vector<int> &link){
    while(x != link[x]) x = link[x];
    return x;
}


bool same(int a, int b, vector<int> &link){
    return find(a, link) == find(b, link);
}


void unite(int a, int b, vector<int> &link, vector<int> &size){
    a = find(a, link);
    b = find(b, link);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}


void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> sets;
    vector<int> left(m);
    for(int i = 0; i < m; i++) cin >> left[i];
    vector<int> right(n);
    for(int i = 0; i < n; i++) cin >> right[i];
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        vector<int> s(x);
        for(int j = 0; j < x; j++){
            cin >> s[j];
        }
        sets.push_back(s);
    }
    debug(left, right, sets);

    ll sum = 0;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++){
        for(int j : sets[i]){
            edges.push_back({left[i] + right[j-1], {i, m + j - 1}});
            sum += left[i] + right[j-1];
        }
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());
    debug(edges);
    vector<int> link(n + m);
    for(int i = 0; i < n + m; i++){
        link[i] = i;
    }
    vector<int> size(n + m, 1);

    ll ans = 0;
    for(auto edge : edges){
        if(!same(edge.second.first, edge.second.second, link)){
            ans += edge.first;
            unite(edge.second.first, edge.second.second, link, size);
            debug(edge);
        }
    }

    cout << sum - ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}