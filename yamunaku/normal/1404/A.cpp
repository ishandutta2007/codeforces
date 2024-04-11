//
// Created by yamunaku on 2020/08/27.
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



void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> one(k, 0), zero(k, 0);
    rep(i, n) {
        if (s[i] == '1') {
            one[i % k]++;
        } else if (s[i] == '0') {
            zero[i % k]++;
        }
    }
    int x=0, y=0;
    rep(i, k) {
        if(one[i] && zero[i]){
            CNO;
            return;
        }
        if(zero[i]) x++;
        if(one[i]) y++;
    }
    if(x <= k/2 && y <= k/2) CYES;
    else CNO;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}