//
// Created by yamunaku on 2019/11/24.
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

void solve(){
    int n, k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;
    vector<pair<int, int>> ans;
    rep(i, k){
        if(s[2 * i] == ')'){
            repl(j, 2 * i + 1, n){
                if(s[j] == '('){
                    ans.emplace_back(2 * i, j);
                    reverse(s.begin() + 2 * i, s.begin() + j + 1);
                    break;
                }
            }
        }
        if(s[2 * i + 1] == '('){
            repl(j, 2 * i + 2, n){
                if(s[j] == ')'){
                    ans.emplace_back(2 * i + 1, j);
                    reverse(s.begin() + 2 * i + 1, s.begin() + j + 1);
                    break;
                }
            }
        }
    }
    int rem = (n-2*k)/2;
    repl(i, 2*k, 2*k+rem){
        if(s[i] == ')'){
            repl(j, i + 1, n){
                if(s[j] == '('){
                    ans.emplace_back(i, j);
                    reverse(s.begin() + i, s.begin() + j + 1);
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto &p:ans){
        cout << p.first + 1 SP p.second + 1 << endl;
    }
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