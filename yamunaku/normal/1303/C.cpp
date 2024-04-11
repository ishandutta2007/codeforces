//
// Created by yamunaku on 2020/02/12.
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
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
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

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        CYES;
        rep(i, 26){
            cout << (char) (i + 'a');
        }
        cout << endl;
        return;
    }
    vector<set<int>> e(26);
    rep(i, n - 1){
        e[s[i] - 'a'].insert(s[i + 1] - 'a');
        e[s[i + 1] - 'a'].insert(s[i] - 'a');
    }
    bool ok = true;
    rep(i, 26){
        if(e[i].size() > 2){
            CNO;
            return;
        }
    }
    rep(i, 26){
        if(e[i].size() == 1){
            int now = *e[i].begin();
            string ans = "";
            ans.push_back(i + 'a');
            while(e[now].size() == 2){
                ans.push_back(now + 'a');
                for(auto &p:e[now]){
                    for(auto &c:ans){
                        if(c == p + 'a') goto next2;
                    }
                    now = p;
                    break;
                    next2:;
                }
            }
            ans.push_back(now + 'a');
            rep(k, 26){
                for(auto &c:ans){
                    if(c == k + 'a') goto next;
                }
                ans.push_back(k + 'a');
                next:;
            }
            CYES;
            cout << ans << endl;
            return;
        }
    }
    CNO;
}

int main(){
    CFS;
    int t;
    cin >> t;
    rep(_, t){
        solve();
    }
    return 0;
}