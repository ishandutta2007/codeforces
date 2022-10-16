#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

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
    vi v(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int out = 0; out < 2 * n - 1; out++){
        debug(v[out]);
        multiset<int> nums;
        vpii ans;
        for(int i = 0; i + 1 < 2 * n; i++){
            if(out == i) continue;
            nums.insert(v[i]);
        }
        ans.push_back({v[2 * n - 1], v[out]});
        int sum = v[2 * n - 1];
        for(int i = 0; i < n-1; i++){
            int maxi = *prev(nums.end());
            int other = sum - maxi;
            debug(maxi, other);
            nums.erase(prev(nums.end()));
            if(nums.find(other) == nums.end()){
                goto next;
            }
            nums.erase(nums.find(other));
            ans.push_back({maxi, other});
            sum = maxi;
            debug(nums);
        }
        cout << "YES" << endl;
        cout << ans[0].first + ans[0].second << endl;
        for(pii p : ans){
            cout << p.first << " " << p.second << endl;
        }
        return;


        next:
        ;
    }
    cout << "NO" << endl;
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