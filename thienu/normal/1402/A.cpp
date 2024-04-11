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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(n == 1){
        cout << "1 1" << endl;
        cout << -v[0] << endl;
        cout << "1 1\n0\n1 1\n0" << endl;
        return;
    }
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        ll x = -(v[i] / (n-1));
        ll y = (n-1) * x;
        if(y > -v[i]){
            x--;
            y -= (n-1);
        }
        debug(i, y);
        ll diff = - y - v[i];
        a[i] = x - diff;
        b[i] = diff;
    }
    debug(a, b);
    cout << 1 << " " << n - 1 << endl;
    for(int i = 0; i < n-1; i++) cout << a[i] * (n-1) << " ";
    cout << endl;
    cout << 2 << " " << n << endl;
    for(int i = 1; i < n-1; i++) cout << 0 << " ";
    cout << a[n-1] * (n-1) << " ";
    cout << endl;
    cout << 1 << " " << n << endl;
    for(int i = 0; i < n; i++) cout << b[i] * n << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}