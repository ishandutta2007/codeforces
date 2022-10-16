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
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    if(n & 1){
        cout << "Second" << endl;
        vector<vector<int>> pairs(n);
        vector<vector<int>> loc(n);
        for(int i = 0; i < 2 * n; i++){
            int x;
            cin >> x;
            x--;
            pairs[x].push_back(i + 1);
            loc[(i+1)%n].push_back(x);
        }
        set<int> unused_pairs, unused_nums;
        for(int i = 0; i < n; i++) unused_pairs.insert(i);
        for(int i = 0; i < n; i++) unused_nums.insert(i);
        set<int> ans;
        ans.insert(pairs[0][0]);
        unused_pairs.erase(0);
        unused_nums.erase(pairs[0][0]%n);
        int next = pairs[0][1]%n;
        for(int i = 0; i < n-1; i++){
            if(unused_nums.find(next) == unused_nums.end()){
                int a = *unused_pairs.begin();
                ans.insert(pairs[a][0]);
                unused_pairs.erase(a);
                unused_nums.erase(pairs[a][0]%n);
                next = pairs[a][1]%n;
            }
            else{
                vector<int> a = loc[next];
                int b = a[0];
                if(unused_pairs.find(a[0]) == unused_pairs.end()){
                    b = a[1];
                }
                int c = pairs[b][0] % n == next ? 0 : 1;
                ans.insert(pairs[b][c]);
                unused_pairs.erase(b);
                unused_nums.erase(pairs[b][c]%n);
                next = pairs[b][1-c]%n;
            }
        }
        int sum = 0;
        for(int i : ans){
            sum = (sum + i) % (2 * n);
        }
        if(sum == 0){
            for(int i : ans) cout << i << " ";
        }
        else{
            for(int i = 1; i <= 2 * n; i++){
                if(ans.find(i) == ans.end()) cout << i << " ";
            }
        }
        cout << endl;
    }
    else{
        cout << "First" << endl;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
                cout << j << " ";
            }
        }
        cout << endl;
    }
    int x;
    cin >> x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}