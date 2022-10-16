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
    // 0 indexed
    queue<int> one;
    queue<pii> two;
    
    int last_3 = -1;
    
    int nxt = n-1;
    vpii ans;
    for(int i = n-1; i >= 0; i--){
        debug(i, one.size(), two.size(), ans);
        if(v[i] == 0) continue;
        if(v[i] == 1){
            one.push(i);
        }
        else if(v[i] == 2){
            if(one.empty()){
                cout << -1 << endl;
                return;
            }
            int a = one.front();
            one.pop();
            two.push({i, a});
        }
        else{
            if(last_3 == -1){
                if(!two.empty()){
                    auto p = two.front();
                    int a = p.first, b = p.second;
                    ans.push_back({nxt, a});
                    ans.push_back({nxt, b});
                    last_3 = a;
                    two.pop();
                }
                else if(!one.empty()){
                    int a = one.front();
                    ans.push_back({nxt, a});
                    last_3 = a;
                    one.pop();
                }
                else{
                    cout << -1 << endl;
                    return;
                }
                nxt--;
            }
            ans.push_back({nxt, i});
            ans.push_back({nxt, last_3});
            last_3 = i;
            nxt--;
        }
    }
    debug(one.size(), two.size(), ans);
    while(!one.empty()){
        int a = one.front();
        one.pop();
        ans.push_back({nxt, a});
        nxt--;
    }
    debug(ans);
    while(!two.empty()){
        auto p = two.front();
        two.pop();
        int a = p.first, b = p.second;
        debug(a, b);
        ans.push_back({nxt, a});
        ans.push_back({nxt, b});
        nxt--;
    }
    debug(ans);
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}