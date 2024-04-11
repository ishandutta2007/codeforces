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

void solve(){
    int n;
    cin >> n;
    vector<int> v(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> v[i];
        v[i]--;
    }

    vector<vector<int>> child(n);
    vector<int> visited(n, 0);
    int next_unused = n-1;

    for(int i = 0; i < n-1; i++){
        debug(i);
        visited[v[i]] = 1;
        while(visited[next_unused]) next_unused--;
        if(i == n-2 || visited[v[i+1]]){
            child[v[i]].push_back(next_unused);
            visited[next_unused] = 1;
        }
        else{
            child[v[i]].push_back(v[i+1]);
            visited[v[i+1]] = 1;
        }
    }

    debug(child);

    cout << v[0] + 1 << endl;

    for(int i = 0; i < n; i++){
        for(int u : child[i]) cout << i+1 << " " << u+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}