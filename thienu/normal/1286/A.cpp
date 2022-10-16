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
    for(int i = 0; i < n; i++) cin >> v[i];
    set<int> odd;
    set<int> even;
    for(int i = 1; i <= n; i++){
        if(i & 1) odd.insert(i);
        else even.insert(i);
    }
    vi nonzero;
    for(int i = 0; i < n; i++){
        if(v[i]){
            nonzero.push_back(i);
            if(v[i] & 1) odd.erase(v[i]);
            else even.erase(v[i]);
        }
    }
    debug(odd, even);
    int no = odd.size();
    int ne = even.size();
    int nz = nonzero.size();
    debug(no, ne, nz);
    if(nz == 0){
        cout << (n & 1 ? 0 : 1) << endl;
        return;
    }
    multiset<int> same_even;
    multiset<int> same_odd;
    multiset<int> different;
    for(int i = 0; i+1 < nz; i++){
        if((v[nonzero[i]] & 1) == (v[nonzero[i+1]] & 1)){
            if(v[nonzero[i]] & 1) same_odd.insert(nonzero[i+1]-nonzero[i]-1);
            else same_even.insert(nonzero[i+1]-nonzero[i]-1);
        }
        else different.insert(nonzero[i+1] - nonzero[i] - 1);
    }
    // if(v[nonzero[0]] & 1) same_odd.insert(nonzero[0]);
    // else same_even.insert(nonzero[0] - 1);
    // if(v[nonzero[nz-1]] & 1) same_odd.insert(n - nonzero[nz-1] - 1);
    // else same_even.insert(n - nonzero[nz-1] - 1);
    debug(same_even, same_odd, different);
    int ans = different.size();
    for(int i : same_even){
        if(ne >= i){
            ne -= i;
        }
        else{
            ans += 2;
        }
    }
    for(int i : same_odd){
        if(no >= i){
            no -= i;
        }
        else{
            ans += 2;
        }
    }
    debug(no, ne, ans);
    if(v[nonzero[0]] & 1 && no < nonzero[0]){
        ans++;
    }
    else if(v[nonzero[0]] & 1){
        no -= nonzero[0];
    }
    if(!(v[nonzero[0]] & 1) && ne < nonzero[0]){
        ans++;
    }
    else if(!(v[nonzero[0]] & 1)){
        ne -= nonzero[0];
    }
    debug(no, ne);
    if(v[nonzero[nz-1]] & 1 && no < n - nonzero[nz-1] - 1) ans++;
    else if(!(v[nonzero[nz-1]] & 1) && ne < n - nonzero[nz-1] - 1) ans++;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}