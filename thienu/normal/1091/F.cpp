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
    vll l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    string type;
    cin >> type;
    ll cg2 = 0;
    bool water = false;
    ll stamina = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(type[i] == 'G'){
            stamina += l[i];
            cg2 += 2 * l[i];
            ans += 5 * l[i];
        }
        else if(type[i] == 'W'){
            water = true;
            stamina += l[i];
            ans += 3 * l[i];
        }
        else{
            stamina -= l[i];
            ans += l[i];
            if(stamina < 0){
                if(water){
                    ans += 3 * -stamina;
                }
                else{
                    ans += 5 * -stamina;
                }
                stamina = 0;
            }
        }
        cg2 = min(cg2, stamina);
    }
    ans -= 2 * cg2;
    ans -= (stamina - cg2);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}