//
// Created by yamunaku on 2019/12/29.
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
    int n;
    cin >> n;
    vl x(n), y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
    }
    int p;
    while(1){
        p = ((x[0] + y[0]) % 2 + 2) % 2;
        int c = 0;
        rep(i, n){
            if(((x[i] + y[i]) % 2 + 2) % 2 == p) c++;
        }
        if(0 < c && c < n) break;
        if(p){
            rep(i, n) x[i]++;
        }
        rep(i, n){
            int tmp = x[i];
            x[i] = (x[i] + y[i]) / 2;
            y[i] = (tmp - y[i]) / 2;
        }
    }
    vi ans;
    rep(i, n){
        if(((x[i] + y[i]) % 2 + 2) % 2 == p) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for(auto &a:ans){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}