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

ll MOD = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    ll ans = 1;

    int j = m-1;
    bool found = false;
    int start;
    int end;
    int last_start = -1;
    if(m == 1){
        last_start = n-1;
        goto check;
    }
    for(int i = n-1; i >= 0; i--){
        while(a[i] < b[j]){
            if(!found){
                cout << 0 << endl;
                return;
            }
            else{
                ans = (ans * (ll) (start - i)) % MOD;
                j--;
                found = false;
                if(j == 0){
                    last_start = i;
                    goto check;
                }
            }
        }
        if(a[i] == b[j] && !found){
            found = true;
            start = i;
        }
    }
    check:
    if(last_start == -1){
        cout << 0 << endl;
        return;
    }
    found = false;
    for(int i = 0; i <= last_start; i++){
        if(a[i] == b[0]){
            found = true;
        }
        else if(a[i] < b[0]){
            cout << 0 << endl;
            return;
        }
    }
    if(!found){
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}