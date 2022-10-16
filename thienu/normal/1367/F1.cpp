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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    
    u_map<int, int> pref;
    int t = 0;
    for(auto const& [i, occ] : cnt){
        pref[i] = t;
        t += occ;
    }

    debug(pref);

    u_map<int, int> running;
    vector<int> nv(n);
    for(int i = 0; i < n; i++){
        nv[i] = pref[v[i]] + running[v[i]];
        running[v[i]]++;
    }

    vector<int> index(n);
    for(int i = 0; i < n; i++){
        index[nv[i]] = i;
    }

    debug(nv);

    vector<int> visited(n, 0);
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int total = 1;
            visited[i] = 1;
            int last = i;
            int next_num = nv[i] + 1;
            while(next_num < n && index[next_num] > last){
                debug(next_num, visited);
                last = index[next_num];
                visited[last] = 1;
                total++;
                next_num++;
            }
            maxi = max(maxi, total);
        }
    }

    debug(maxi);

    debug("ans--------------------------", n-maxi);

    cout << n - maxi << endl;
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