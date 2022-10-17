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
    const ld pi = abs(atan2((ld)0, (ld)-1));
    ll n;
    cin >> n;
    vector<ld> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    ll ans = 0;
    rep(t, n){
        vector<ld> v;
        rep(i, n){
            if(i != t){
                v.push_back(atan2(y[i] - y[t], x[i] - x[t]));
            }
        }
        sort(all(v));
        if(v[n - 2] - v[0] <= pi) continue;
        ans += (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
        rep(i, n - 1) v.push_back(v[i] + 2 * pi);
        int tmp = 0;
        int now = 0;
        ll s;
        rep(i, n - 1){
            while(now < 2 * (n - 1)){
                if(v[now] > v[i] + pi) break;
                now++;
            }
            s = now - i - 1;
            ans -= s * (s - 1) * (s - 2) / 6;
            tmp += s * (s - 1) * (s - 2) / 6;
        }
    }
    cout << ans << endl;
    return 0;
}