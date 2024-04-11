//
// Created by yamunaku on 2020/01/04.
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
    ll n;
    cin >> n;
    vi ok(n, false), ma(n, 0), mi(n, IINF);
    ll c = 0;
    rep(i, n){
        int l;
        cin >> l;
        int x;
        rep(j, l){
            cin >> x;
            if(x > mi[i]) ok[i] = true;
            ma[i] = max(ma[i], x);
            mi[i] = min(mi[i], x);
        }
        if(ok[i]){
            c++;
            ma[i] = -1;
        }
    }
    ll ans = n * n - (n - c) * (n - c);
    sort(all(ma));
    rep(i, n){
        if(!ok[i]){
            ans += n - (lower_bound(all(ma), mi[i] + 1) - ma.begin());
        }
    }
    cout << ans << endl;
    return 0;
}