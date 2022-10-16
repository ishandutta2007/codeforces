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
    int n, m;
    cin >> n >> m;
    ll x, y; int k;
    cin >> x >> k >> y;
    vector<int> a(n+1), b(m+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    a[n] = 0;
    b[m] = 0;

    debug(a, b);

    auto it = b.begin();
    int left = 0;
    int left_idx = -1;
    int maxi = 0;
    ll ans = 0;
    for(int i = 0; i < n+1; i++){
        if(a[i] == *it){
            // process range
            int length = i - left_idx - 1;
            bool can_beserk = maxi < max(left, a[i]);
            if(x <= y * k){
                // cheap fireball
                if(length < k && !can_beserk){
                    cout << -1 << endl;
                    return;
                }
                ans += x * (length / k) + y * (length % k);
            }
            else{
                // cheap beserk
                if(can_beserk){
                    ans += y * length;
                }
                else{
                    if(length < k){
                        cout << -1 << endl;
                        return;
                    }
                    ans += y * (length - k) + x;
                }
            }
            debug(length, maxi, left, a[i], x, y, k, can_beserk, ans);

            left = *it;
            left_idx = i;
            maxi = 0;
            it++;
        }
        else{
            maxi = max(maxi, a[i]);
            debug(i, a[i], maxi);
        }
    }
    if(it != b.end()){
        cout << -1 << endl;
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