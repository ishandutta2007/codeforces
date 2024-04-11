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

string answer(string prefix, int len, int k){
    set<int> used;
    for(char c : prefix){
        used.insert(c-'0');
    }
    if(used.size() > k){
        return "";
    }
    int digit;
    if(used.size() == k){
        digit = *used.begin();
    }else{
        digit = 0;
    }
    for(int i = prefix.size(); i < len; i++){
        prefix += (char)(digit+'0');
    }
    return prefix;
}

void solve(){
    string s;
    int k;
    cin >> s >> k;
    int len = s.size();
    if(answer(s, len, k) != ""){
        cout << s << endl;
        return;
    }
    for(int i = len-1; i >= 0; i--){
        for(char c = s[i]+1; c <= '9'; c++){
            string pref;
            for(int j = 0; j < i; j++){
                pref += s[j];
            }
            pref += c;
            string ans = answer(pref, len, k);
            if(ans != ""){
                cout << ans << endl;
                return;
            }
        }
    }
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