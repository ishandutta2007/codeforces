//
// Created by yamunaku on 2020/04/23.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    //CFS;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> cost(n);
    vector<int> mi(n + 1, 0);
    vector<string> num = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010",
                          "1111111", "1111011"};
    rep(i, n){
        string s;
        cin >> s;
        cost[i] = vector<int>(10);
        rep(j, 10){
            int c = 0;
            rep(t, 7){
                if(s[t] == '0' && num[j][t] == '1'){
                    c++;
                }else if(s[t] == '1' && num[j][t] == '0'){
                    c = IINF;
                }
            }
            cost[i][j] = c;
            mi[i] = min(mi[i], cost[i][j]);
        }
        if(mi[i] > k){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, false));
    dp[n][k] = true;
    per(i, n){
        rep(j, k + 1){
            rep(t, 10){
                if(j + cost[i][t] <= k){
                    if(dp[i + 1][j + cost[i][t]]) dp[i][j] = true;
                }
            }
        }
    }
    if(!dp[0][0]){
        cout << -1 << endl;
        return 0;
    }
    string ans;
    int now = 0;
    rep(i, n){
        per(j, 10){
            if(now + cost[i][j] > k) continue;
            if(dp[i + 1][now + cost[i][j]]){
                now += cost[i][j];
                ans.push_back('0' + j);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}