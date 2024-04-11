//
// Created by yamunaku on 2019/11/19.
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

struct aaa{
    ll c;
    ll pos;
    ll t;
};

int main(){
    CFS;
    int n;
    cin >> n;
    vl a(n);
    ll num = 0;
    rep(i, n) cin >> a[i], num += a[i];
    vi cand;
    for(int k = 2; k <= sqrt(num) + 1; k++){
        if(num % k == 0){
            while(num % k == 0) num /= k;
            cand.push_back(k);
        }
    }
    if(num > 1)cand.push_back(num);
    if(cand.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = LINF;
    for(auto &k:cand){
        vl b(n);
        rep(i, n) b[i] = a[i] % k;
        vector<aaa> v;
        vector<int> mid(n, -1);
        ll c = 0;
        int now = 0;
        rep(i, n){
            if(c + b[i] >= k){
                v.push_back({k - c, i, now});
                if(mid[now] == -1) mid[now] = i;
                now++;
                mid.push_back(-1);
                v.push_back({b[i] - (k - c), i, now});
                c = (c + b[i]) % k;
            }else{
                v.push_back({b[i], i, now});
                c += b[i];
            }
            if(c > k / 2 && mid[now] == -1) mid[now] = i;
        }
        ll tmp = 0;
        for(auto &p:v){
            tmp+=p.c*abs(p.pos-mid[p.t]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}