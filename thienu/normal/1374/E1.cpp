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

int INF = 1e9 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    int counta = 0, countb = 0;
    vector<int> both, alice, bob;
    for(int i = 0; i < n; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(a == 1) counta++;
        if(b == 1) countb++;
        if(a == 1 && b == 1){
            both.push_back(t);
        }
        else if(a == 1){
            alice.push_back(t);
        }
        else if(b == 1){
            bob.push_back(t);
        }
    }
    debug(both, alice, bob);
    if(min(counta, countb) < k){
        cout << -1 << endl;
        return;
    }
    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    vector<int> one;
    for(int i = 0; i < min(alice.size(), bob.size()); i++){
        one.push_back(alice[i] + bob[i]);
    }
    one.push_back(INF);
    both.push_back(INF);
    debug(one, both);
    int a = 0, b = 0, ans = 0;
    for(int i = 0; i < k; i++){
        if(both[a] > one[b]){
            ans += one[b];
            b++;
        }
        else{
            ans += both[a];
            a++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}