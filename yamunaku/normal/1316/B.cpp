//
// Created by yamunaku on 2020/03/04.
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
    CFS;
    int t;
    cin >> t;
    rep(_, t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<string> f(n);
        rep(i, n){
            f[i] = s.substr(i, n - i);
            string x = s.substr(0, i);
            if((n - i) & 1) reverse(all(x));
            f[i] += x;
        }
        vi idx(n);
        iota(all(idx), 0);
        sort(all(idx), [&](int &l, int &r){
            return f[l] == f[r] ? l < r : f[l] < f[r];
        });
        cout << f[idx[0]] << endl;
        cout << idx[0] + 1 << endl;
    }
    return 0;
}