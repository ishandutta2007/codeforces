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



int count_zeros(string s){
    int ans = 0;
    for(char c : s){
        if(c == '0') ans++;
    }
    return ans;
}

void solve(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    if(count_zeros(s) != count_zeros(t)){
        cout << "-1" << endl;
        return;
    }

    string f = "";
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            f += s[i];
        }
    }
    int a = f.size();

    int zero = 0, one = 0;
    int mzero = 0, mone = 0;
    for(int i = 0; i < a; i++){
        if(f[i] == '0'){
            if(one > 0) one--;
            else zero++;
        }
        else{
            if(zero > 0) zero--;
            else one++;
        }
        mzero = max(zero, mzero);
        mone = max(one, mone);
    }

    cout << mzero + mone << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}