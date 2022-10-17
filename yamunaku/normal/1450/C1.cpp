//
// Created by yamunaku on 2020/12/06.
//

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

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

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vi c(3);
    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == 'X') {
                c[(i + j) % 3]++;
            }
        }
    }
    int k = 0;
    rep(i, 3) if (c[i] < c[k]) k = i;
    rep(i,n){
        rep(j,n){
            if(s[i][j] == 'X' && (i + j) % 3 == k){
                s[i][j] = 'O';
            }
        }
        cout << s[i] << endl;
    }
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}