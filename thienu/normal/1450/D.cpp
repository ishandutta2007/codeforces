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
    vi v(n);
    vi cnt(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]-1]++;
    }
    if(cnt[0] == 0){
        for(int i = 0; i < n; i++){
            cout << 0;
        }
        cout << endl;
        return;
    }

    bool start_perm = *min_element(cnt.begin(), cnt.end()) == 1;

    int left = 0, right = n-1;
    int p = 1;
    while(((left == n || v[left] >= p) && (right == 0 || v[right] >= p)) && v[left] != v[right] && ((left < n && v[left] == p) || (right > 0 && v[right] == p))){
        if(v[left] == p) left++;
        else right--;
        p++;
    }

    debug(left, right, p);

    int low_idx = distance(v.begin(), min_element(v.begin() + left, v.begin() + right + 1));
    debug(low_idx);

    int l = low_idx, r = low_idx;
    while(l >= 0 && v[l] >= v[low_idx]) l--;
    while(r < n && v[r] >= v[low_idx]) r++;
    int removed = r - l - 2;
    if(v[low_idx] > p) removed++;
    int remaining = n - removed;

    debug(l, r, removed, remaining);

    vi ans(n);
    ans[0] = start_perm;
    for(int i = n - remaining; i < n; i++) ans[i] = 1;

    for(int i : ans){
        cout << i;
    }
    cout << endl;
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