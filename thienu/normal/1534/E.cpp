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

int query(vi values){
    cout << "?";
    for(int i : values){
        cout << ' ' << i+1;
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int ans){
    cout << "! " << ans << endl;
}

void solve(){
    int n, k;
    cin >> n >> k;
    if((n & 1) & ((k & 1) ^ 1)){
        cout << -1 << endl;
        return;
    }
    if((n & 1) || (n >= 2 * k) || (n == k)){
        // normal
        int cur = 0;
        int ans = 0;
        while((n - cur) >= 2 * k || ((n - cur) & 1)){
            vi v;
            for(int i = cur; i < cur+k; i++){
                v.push_back(i);
            }
            int out = query(v);
            ans ^= out;
            cur += k;
        }
        if(cur == n){

        }
        else if(cur + k == n){
            vi v;
            for(int i = cur; i < cur+k; i++){
                v.push_back(i);
            }
            int out = query(v);
            ans ^= out;
            cur += k;
        }
        else{
            int rem = (n - cur) / 2;
            int pad = k - rem;
            debug(rem, pad);
            vi s;
            for(int i = 0; i < pad; i++){
                s.push_back(i);
            }
            for(int i = cur; i < n; i += rem){
                vi v = s;
                for(int j = 0; j < rem; j++){
                    v.push_back(i + j);
                }
                int out = query(v);
                ans ^= out;
                cur += k;
            }
        }
        answer(ans);
    }
    else if((k & 1) ^ 1){
        vi v;
        for(int i = 0; i < k; i++){
            v.push_back(i);
        }
        int ans = 0;
        int out = query(v);
        ans ^= out;
        int cur = k;
        int rem = (n - cur) / 2;
        int pad = k - rem;
        debug(rem, pad);
        vi s;
        for(int i = 0; i < pad; i++){
            s.push_back(i);
        }
        for(int i = cur; i < n; i += rem){
            vi v = s;
            for(int j = 0; j < rem; j++){
                v.push_back(i + j);
            }
            int out = query(v);
            ans ^= out;
            cur += k;
        }
        answer(ans);
    }
    else{
        int ans = 0;
        int m = (n - k) * 2;
        debug(m);
        int cur = 0;
        while(cur < n){
            // from cur to min(cur + m, n)
            int sz = min(n-cur, m);
            int pz = k-sz/2;
            vi pad;
            for(int i = 0; i < n; i++){
                if(pad.size() == pz) break;
                if(i < cur || i >= cur + sz) pad.push_back(i);
            }
            debug(cur, sz, pz, pad);
            for(int i = cur; i < cur + sz; i += sz / 2){
                vi v = pad;
                for(int j = 0; j < sz/2; j++){
                    v.push_back(i+j);
                }
                int out = query(v);
                ans ^= out;
            }
            cur += sz;
        }
        answer(ans);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}