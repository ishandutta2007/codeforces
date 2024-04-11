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
    vector<string> s(3);
    for(int i = 0; i < 3; i++) cin >> s[i];

    vi ptr(3);
    string ans = "";
    while(*max_element(ptr.begin(), ptr.end()) != 2*n){
        debug(ans, ptr);
        vi cnt(2);
        for(int i = 0; i < 3; i++){
            cnt[s[i][ptr[i]]-'0']++;
        }
        char sel;
        if(cnt[1] > cnt[0]){
            sel = '1';
        }
        else{
            sel = '0';
        }
        for(int i = 0; i < 3; i++){
            if(s[i][ptr[i]] == sel){
                ptr[i]++;
            }
        }
        ans += sel;
    }
    debug(ptr, ans);
    int done = distance(ptr.begin(), max_element(ptr.begin(), ptr.end()));

    int next;
    int maxi = -1;
    for(int i = 0; i < 3; i++){
        if(i == done) continue;
        if(ptr[i] > maxi){
            next = i;
            maxi = ptr[i];
        }
    }
    while(ptr[next] < 2*n){
        ans += s[next][ptr[next]];
        ptr[next]++;
    }
    cout << ans << endl;
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