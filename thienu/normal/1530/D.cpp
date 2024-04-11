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
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }
    vvi want(n);
    for(int i = 0; i < n; i++){
        want[v[i]].push_back(i);
    }
    vi ans(n);
    int num_assigned = 0;
    vi has_gift(n), has_wish(n);
    for(int i = 0; i < n; i++){
        if(!want[i].empty()){
            ans[want[i][0]] = i;
            has_gift[i] = 1;
            has_wish[want[i][0]] = 1;
            num_assigned++;
        }
    }
    debug(has_gift, has_wish);
    vi no_gift;
    vi no_wish;
    vi no_both;
    for(int i = 0; i < n; i++){
        if(!has_wish[i] && !has_gift[i]){
            no_both.push_back(i);
        }else if(!has_wish[i]){
            no_wish.push_back(i);
        }else if(!has_gift[i]){
            no_gift.push_back(i);
        }
    }
    if(num_assigned + 1 == n && !no_both.empty()){
        int x = no_both[0];
        int steal = want[v[x]][0];
        ans[steal] = x;
        ans[x] = v[x];
    }else{
        for(int i : no_both){
            no_gift.push_back(i);
            no_wish.push_back(i);
        }
        debug(no_gift, no_wish);
        for(int i = 0; i < no_gift.size(); i++){
            ans[no_wish[i]] = no_gift[(i+1)%(no_gift.size())];
        }
    }
    debug(ans);
    cout << num_assigned << endl;

    for(int i : ans){
        cout << i+1 << ' ';
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