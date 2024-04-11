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
    int n, d, m;
    cin >> n >> d >> m;
    multiset<int, greater<int>> a, b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= m) a.insert(x);
        else b.insert(x);
    }
    debug(a, b);

    ll ans;
    if(b.empty()){
        ans += *a.begin();
        a.erase(a.begin());
    }
    else{
        ans += *b.begin();
        b.erase(b.begin());
    }
    n--;
    while(n % (d+1) != 0){
        if(!a.empty()){
            ans += *a.begin();
            a.erase(a.begin());
        }
        n--;
    }
    debug(ans);

    while(n){
        ll asum = 0;
        auto it = a.begin();
        for(int i = 0; i < min(d+1, (int) a.size()); i++){
            asum += *it;
            it++;
        }
        ll bsum = (b.empty() ? 0 : *b.begin());
        debug(n, asum, bsum, a, b);
        if(asum > bsum){
            ans += asum;
            int num_remove = min(d+1, (int) a.size());
            for(int i = 0; i < num_remove; i++){
                a.erase(a.begin());
            }
        }
        else{
            ans += bsum;
            b.erase(b.begin());
        }
        n -= (d+1);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}