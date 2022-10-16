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

int odd_primes(int x){
    int ans = 0;
    while(x % 2 == 0){
        x /= 2;
    }
    for (long long d = 3; d * d <= x; d++) {
        while (x % d == 0 && x > 0) {
            ans++;
            x /= d;
        }
    }
    if (x > 1)
        ans++;
    return ans;
}

int largepow2(int x){
    int ans = 0;
    while(true){
        if(x % 2 == 1 || x == 0){
            break;
        }
        x = x / 2;
        ans++;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int state = odd_primes(n);
    // debug(state);
    bool misere = largepow2(n) == 1;
    debug(state, largepow2(n), misere);
    if((!misere && state > 0) || (misere && state != 1)){
        cout << "Ashishgup" << endl;
    }
    else{
        cout << "FastestFinger" << endl;
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