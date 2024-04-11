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


void mv(vi &v, int x, vi &ans, int &pos0, int &pos1){
    for(int l = 0, r = x-1; l < r; l++, r--){
        swap(v[l], v[r]);
        if(pos0 == l) pos0 = r;
        else if(pos0 == r) pos0 = l;
        if(pos1 == l) pos1 = r;
        else if(pos1 == r) pos1 = l;
    }
    ans.push_back(x);
}


void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }
    for(int i = 0; i < n; i++){
        if((i ^ v[i]) & 1){
            cout << -1 << endl;
            return;
        }
    }
    vi ans;
    for(int i = n-2; i >= 0; i-=2){
        int pos0, pos1;
        // get i+1/i
        for(int j = 0; j < n; j++){
            if(v[j] == i+1) pos1 = j;
            if(v[j] == i) pos0 = j;
        }
        // move i+1 to beginning
        mv(v, pos1+1, ans, pos0, pos1);
        // move i+1 before i
        mv(v, pos0, ans, pos0, pos1);
        // move to start
        mv(v, pos0 + 2, ans, pos0, pos1);
        mv(v, 3, ans, pos0, pos1);
        mv(v, i+2, ans, pos0, pos1);
    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;

    debug(v);
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