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
    vpii s(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        s[i] = {v[i], i};
    }

    sort(s.begin(), s.end());

    vi vis(n);

    int maxi = 0;
    vi ans;
    for(pii p : s){
        int i = p.second;
        if(vis[i]) continue;
        int left = i, right = i;
        while(left > 0 && v[left - 1] % v[i] == 0 && !(v[i] == v[left - 1] && vis[left - 1])){
            left--;
            vis[left] = 1;
        }
        while(right < n-1 && v[right + 1] % v[i] == 0 && !(v[i] == v[right + 1] && vis[right + 1])){
            right++;
            vis[right] = 1;
        }
        vis[i] = 1;
        if(right - left > maxi){
            maxi = right - left;
            ans.clear();
            ans.push_back(left);
        }
        else if(right - left == maxi){
            ans.push_back(left);
        }
        debug(i, v, vis);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " " << maxi << endl;
    for(int i : ans) cout << i+1 << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}