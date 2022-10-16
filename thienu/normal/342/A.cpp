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
    vector<int> cnt(10);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 5 || x == 7){
            cout << -1 << endl;
            return;
        }
        cnt[x]++;
    }
    debug(cnt);
    vector<vector<int>> ans(n/3, vector<int>(3));
    int i = 0;
    while(n){
        if(cnt[4] > 0){
            if(cnt[1] == 0 || cnt[2] == 0){
                cout << -1 << endl;
                return;
            }
            ans[i][0] = 1;
            ans[i][1] = 2;
            ans[i][2] = 4;
            cnt[4]--;
            cnt[2]--;
            cnt[1]--;
        }
        else if(cnt[6] > 0 && cnt[3] > 0){
            if(cnt[1] == 0){
                cout << -1 << endl;
                return;
            }
            ans[i][0] = 1;
            ans[i][1] = 3;
            ans[i][2] = 6;
            cnt[6]--;
            cnt[3]--;
            cnt[1]--;
        }
        else if(cnt[6] > 0 & cnt[2] > 0){
            if(cnt[1] == 0){
                cout << -1 << endl;
                return;
            }
            ans[i][0] = 1;
            ans[i][1] = 2;
            ans[i][2] = 6;
            cnt[6]--;
            cnt[2]--;
            cnt[1]--;
        }
        else{
            cout << -1 << endl;
            return;
        }
        n-=3;
        i++;
    }
    debug(ans);
    for(auto v : ans){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}