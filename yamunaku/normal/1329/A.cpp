//
// Created by yamunaku on 2020/04/03.
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
    int n, m;
    cin >> n >> m;
    vi a(m);
    rep(i, m) cin >> a[i];
    ll sum = 0;
    rep(i, m){
        if(a[i] > n - i){
            cout << -1 << endl;
            return 0;
        }
        sum += a[i];
    }
    if(sum < n){
        cout << -1 << endl;
        return 0;
    }
    sum -= n;
    int now = 1;
    rep(i, m){
        cout << now << " ";
        ll x = a[i] - 1;
        now += a[i] - min(x, sum);
        sum -= min(x, sum);
    }
    cout << endl;
    return 0;
}