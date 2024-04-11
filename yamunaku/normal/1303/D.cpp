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
    ll n, m;
    cin >> n >> m;
    vl a(m);
    ll sum = 0;
    vi c(65, 0);
    rep(i, m){
        cin >> a[i];
        sum += a[i];
        rep(j, 32){
            if(a[i] & (1ll << j)){
                c[j]++;
                break;
            }
        }
    }
    if(sum < n){
        cout << -1 << endl;
        return;
    }
    int p = 0;
    ll ans = 0;
    while(n){
        if(n & 1){
            repl(i, p, 64){
                if(c[i] > 0){
                    ans += i - p;
                    c[i]--;
                    perl(j, p, i){
                        c[j]++;
                    }
                    break;
                }
            }
        }
        c[p + 1] += c[p] / 2;
        p++;
        n >>= 1;
    }
    cout << ans << endl;
}

int main(){
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}