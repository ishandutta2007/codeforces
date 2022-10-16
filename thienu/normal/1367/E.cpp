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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> occ;
    for(char c : s){
        occ[c]++;
    }
    vector<int> freq;
    for(char c = 'a'; c <= 'z'; c++){
        if(occ[c] != 0){
            freq.push_back(occ[c]);
        }
    }
    debug(occ, freq);
    int ans = 0;
    vector<int> best(k+1);
    vector<int> times(freq.size(), 0);
    for(int cycle = 1; cycle <= k; cycle++){
        int maxi;
        int maxv = -1;
        for(int i = 0; i < freq.size(); i++){
            int v = freq[i] / (times[i] + 1);
            if(v > maxv){
                maxi = i;
                maxv = v;
            }
        }
        times[maxi]++;
        best[cycle] = maxv;
    }
    debug(best);
    for(int cycle = 1; cycle <= k; cycle++){
        if(k % cycle == 0){
            ans = max(ans, best[cycle] * cycle);
        }
    }
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