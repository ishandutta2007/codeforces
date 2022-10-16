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

bool rollback(vll &v){
    int n = v.size();
    for(int i = 0; i+1 < n; i++){
        if(v[i] >= v[i+1]) return false;
    }
    for(int i = n-1; i >= 1; i--){
        v[i] -= v[i-1];
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vll a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    if(n == 1){
        if(a[0] == b[0]){
            cout << "SMALL\n0\n\n";
        }else{
            cout << "IMPOSSIBLE\n";
        }
    }else if(n == 2){
        vector<pair<char, ll>> ans;
        ll cntp = 0;
        while(true){
            debug(b);
            if(a == b) break;
            if(b[0] == b[1]){
                cout << "IMPOSSIBLE\n";
                return;
            }
            if(b[0] > b[1]){
                reverse(b.begin(), b.end());
                ans.push_back({'R', 1});
            }else if(b[0] == a[0] || b[0] == a[1]){
                bool f = false;
                if(b[0] == a[1]){
                    f = true;
                    swap(a[0], a[1]);
                }
                ll diff = b[1] - a[1];
                if(diff >= 0 && diff % b[0] == 0){
                    ans.push_back({'P', diff / b[0]});
                    cntp += diff / b[0];
                    if(f){
                        ans.push_back({'R', 1});
                    }
                    break;
                }else{
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }else{
                ll times = b[1] / b[0];
                ans.push_back({'P', times});
                cntp += times;
                b[1] -= times * b[0];
                if(b[1] == 0){
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }
        }
        // debug(cntp, cntp > 200000LL);
        if(cntp > 200000LL){
            cout << "BIG\n" << cntp << '\n';
        }else{
            reverse(ans.begin(), ans.end());
            ll tot = 0;
            for(auto p : ans){
                tot += p.second;
            }
            cout << "SMALL\n" << tot << '\n';
            for(auto p : ans){
                for(int i = 0; i < p.second; i++){
                    cout << p.first;
                }
            }
            cout << '\n';
        }
    }else{
        int reverses = 0;
        string ans = "";
        ll cntp = 0;
        while(b != a){
            debug(b);
            debug(ans);
            if(reverses == 2){
                cout << "IMPOSSIBLE\n";
                return;
            }
            if(rollback(b)){
                ans += 'P';
                cntp++;
                reverses = 0;
            }else{
                reverse(b.begin(), b.end());
                ans += 'R';
                reverses++;
            }
        }
        if(cntp > 200000LL){
            cout << "BIG\n" << cntp << '\n';
        }else{
            reverse(ans.begin(), ans.end());
            cout << "SMALL\n" << ans.size() << '\n' << ans << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}