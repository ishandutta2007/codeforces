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
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int minv = 1e9 + 5;
    int maxv = 0;
    for(int i : v){
        minv = min(minv, i);
        maxv = max(maxv, i);
    }

    int minx = max(maxv - n + 1, 0);
    int maxx = maxv;

    // vector<int> below(4001);
    // for(int i = 0; i < n; i++){
    //     for(int j = v[i]; j <= 4000; j++) below[j]++;
    // }
    sort(v.begin(), v.end());
    map<int, int> below;
    // number of a <= x
    int ptr = -1;
    for(int j = minx; j <= maxx + n - 1; j++){
        while(ptr < n-1 && v[ptr+1] <= j) ptr++;
        below[j] = ptr+1;
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = max(minx, v[i]); j <= maxx + n - 1; j++){
    //         below[j]++;
    //     }
    // }
    debug(below);

    // vector<int> bad_below(p, 0);
    // vector<int> bad_above(p, 1e9 + 5);
    vector<vector<pair<int, int>>> bad_ranges(p);
    for(int xi = minx; xi <= maxx + n - 1; xi++){
        // below[xi] - i != 0 (mod p), x between xi - n + 1 and xi
        int i = below[xi] % p;
        int x = (xi - i + p) % p;
        // bad_below[x] = max(bad_below[x], xi);
        // bad_above[x] = min(bad_above[x], xi - n + 1);

        int low = xi - n + 1;
        int high = xi;
        debug(xi, i, x, low, high);

        bool ok = false;
        for(auto &range : bad_ranges[x]){
            if(range.first <= high && range.second >= low){
                range.second = max(range.second, high);
                range.first = min(range.first, low);
                ok = true;
            }
        }
        if(!ok){
            bad_ranges[x].push_back(make_pair(low, high));
        }
    }
    debug(bad_ranges);
    vector<int> ans;
    for(int x = minx; x <= maxx; x++){
        int m = x%p;
        bool ok = true;
        for(auto range : bad_ranges[m]){
            if(x >= range.first && x <= range.second){
                ok = false;
                break;
            }
        }
        if(ok) ans.push_back(x);
    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}