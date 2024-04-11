//
// Created by yamunaku on 2020/08/12.
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
    int n, d, m;
    cin >> n >> d >> m;
    vl a(n);
    rep(i, n) cin >> a[i];
    sort(all(a), greater<ll>());
    vl b, c;
    rep(i, n){
        if(a[i] > m) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    int csz = c.size();
    ll bsum = 0, csum = 0;
    rep(i, csz){
        csum += c[i];
    }
    ll ans = csum;
    int pre = 0;
    rep(i, b.size()){
        int num = 1 + i * (d + 1);
        if(num > n) break;
        bsum += b[i];
        int d = min(csz, max(0, n - pre)) - min(csz, max(0, n - num));
        rep(j, d){
            csum -= c.back();
            c.pop_back();
        }
        pre = num;
        ans = max(ans, csum + bsum);
    }
    cout << ans << endl;
    return 0;
}