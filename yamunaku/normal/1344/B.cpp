//
// Created by yamunaku on 2020/05/06.
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    bool line = false, row = false;
    rep(i, n){
        int c = 0;
        rep(j, m){
            if(c == 2 && s[i][j] == '#') c++;
            if(c == 1 && s[i][j] == '.') c++;
            if(c == 0 && s[i][j] == '#') c++;
        }
        if(c == 3){
            cout << -1 << endl;
            return 0;
        }
        if(c == 0) line = true;
    }
    rep(i, m){
        int c = 0;
        rep(j, n){
            if(c == 2 && s[j][i] == '#') c++;
            if(c == 1 && s[j][i] == '.') c++;
            if(c == 0 && s[j][i] == '#') c++;
        }
        if(c == 3){
            cout << -1 << endl;
            return 0;
        }
        if(c == 0) row = true;
    }
    if(line ^ row){
        cout << -1 << endl;
        return 0;
    }
    vi x(m - 1, false);
    rep(i, n){
        rep(j, m - 1){
            if(s[i][j] == '#' && s[i][j + 1] == '#') x[j] = true;
        }
    }
    int ans = 0;
    rep(i, m){
        if(i > 0) if(x[i - 1]) continue;
        rep(j, n){
            if(s[j][i] == '#'){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}