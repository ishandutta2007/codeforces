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
    int n, k;
    cin >> n >> k;
    vi v(n*k);
    vvi color(n);
    for(int i = 0; i < n*k; i++){
        cin >> v[i];
        debug(v[i]);
        debug("1");
        v[i]--;
        debug(v[i]);
        debug(color[v[i]]);
        color[v[i]].push_back(i);
        debug(color[v[i]]);
    }
    int permitted = n/(k-1) + (n % (k-1) > 0);
    debug(permitted);
    vi used(n);
    vpii ans(n);
    for(int i = 0; i < k-1; i++){
        vector<pair<pii, int>> cand;
        for(int j = 0; j < n; j++){
            cand.push_back({{color[j][i+1], color[j][i]}, j});
        }
        sort(cand.begin(), cand.end());
        int got = 0;
        for(int j = 0; j < n; j++){
            if(got == permitted) continue;
            if(used[cand[j].second]) continue;
            used[cand[j].second] = true;
            ans[cand[j].second] = {cand[j].first.second, cand[j].first.first};
            got++;
        }
    }
    for(pii p : ans){
        cout << p.first+1 << ' ' << p.second+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}