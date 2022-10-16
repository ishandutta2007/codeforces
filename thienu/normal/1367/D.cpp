#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }

    sort(s.begin(), s.end(), greater<char>());
    debug(s, m, v);

    map<char, int> cnt;
    for(char c : s){
        cnt[c]++;
    }
    
    debug(cnt);

    auto current = cnt.rbegin();

    vector<char> ans(m);

    int left = m;
    while(left){
        vector<int> zeros;
        for(int i = 0; i < m; i++){
            if(v[i] == 0){
                zeros.push_back(i);
                left--;
                v[i] = -1;
            }
        }
        while(current->second < zeros.size()){
            current++;
        }
        debug(zeros, left);
        for(int i : zeros){
            debug((int) current->first);
            ans[i] = current->first;
        }
        for(int i = 0; i < m; i++){
            for(int j : zeros){
                v[i] -= abs(i-j);
            }
        }
        current++;
    }

    debug(ans);

    string out = "";
    for(char c : ans){
        out += c;
    }
    cout << out << endl;
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