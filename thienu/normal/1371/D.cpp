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

int f(int n, vector<vector<int>> &a){
    int minr = 1e9 + 5, maxr = 0, minc = 1e9 + 5, maxc = 0;
    for(int i = 0; i < n; i++){
        int s = 0;
        for(int j = 0; j < n; j++){
            s += a[i][j];
        }
        minr = min(minr, s);
        maxr = max(maxr, s);
    }
    for(int i = 0; i < n; i++){
        int s = 0;
        for(int j = 0; j < n; j++){
            s += a[j][i];
        }
        minc = min(minc, s);
        maxc = max(maxc, s);
    }

    return (maxr-minr) * (maxr-minr) + (maxc - minc) * (maxc - minc);
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int x = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x == k) goto end;
            a[j][(i+j)%n] = 1;
            x++;
        }
    }
    end:
    debug(a);
    cout << f(n, a) << endl;
    for(vector<int> v : a){
        for(int i : v){
            cout << i;
        }
        cout << endl;
    }
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