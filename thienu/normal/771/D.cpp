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

const int N = 80;
int dp[N][N][N][2];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'V'){
            s[i] = 'a';
            a++;
        }else if(s[i] == 'K'){
            s[i] = 'b';
            b++;
        }else{
            s[i] = 'c';
            c++;
        }
    }
    debug(s);
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                for(int l = 0; l < 2; l++){
                    dp[i][j][k][l] = 1e9;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                vi used(n);
                vi cnt(3);
                vi target = {i, j, k};
                vi cost(3);
                int cur = 0;
                for(int i = 0; i < n; i++){
                    if(cnt[s[i]-'a'] < target[s[i]-'a']){
                        used[i] = 1;
                    }else{
                        if(cnt[s[i]-'a'] == target[s[i]-'a']){
                            cost[s[i]-'a'] = cur;
                        }
                        cur++;
                    }
                    cnt[s[i]-'a']++;
                }
                debug(i, j, k, used);
                for(int l = 0; l < 2; l++){
                    if(i < a){
                        dp[i+1][j][k][1] = min(dp[i+1][j][k][1], dp[i][j][k][l] + cost[0]);
                    }
                    if(j < b && l == 0){
                        dp[i][j+1][k][0] = min(dp[i][j+1][k][0], dp[i][j][k][l] + cost[1]);
                    }
                    if(k < c){
                        dp[i][j][k+1][0] = min(dp[i][j][k+1][0], dp[i][j][k][l] + cost[2]);
                    }
                }
            }
        }
    }
    cout << min(dp[a][b][c][0], dp[a][b][c][1]) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}