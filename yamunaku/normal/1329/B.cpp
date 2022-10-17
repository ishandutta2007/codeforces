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

ll modpow(ll x, ll a, ll m){
    ll ans = 1;
    while(a){
        if(a & 1) ans = ans * x % m;
        a >>= 1;
        x = x * x % m;
    }
    return ans;
}


int main(){
    //CFS;
    int t;
    cin >> t;
    rep(_, t){
        ll d, m;
        cin >> d >> m;
        ll tmp = d;
        ll k = 0;
        while(tmp){
            tmp >>= 1;
            k++;
        }
        vl ans(k + 1, 0);
        ans[0] = 1;
        repl(i, 1, k + 1){
            rep(j, i){
                ans[i] += ans[j];
            }
            ans[i] = ans[i] % m * (min((1ll << i), d + 1) - (1 << (i - 1))) % m;
        }
        ll sum = 0;
        rep(i, k + 1) sum += ans[i];
        sum = (sum + m - 1) % m;
        cout << sum << endl;
    }
    return 0;
}