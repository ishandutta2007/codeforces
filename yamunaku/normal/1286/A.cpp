//
// Created by yamunaku on 2020/01/05.
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
    // CFS;
    int n;
    cin >> n;
    vi p(n);
    int gu = (n + 1) / 2, ki = n / 2;
    int ans = 0;
    vi x, y;
    vi v, w;
    int l = 0, pre = -1;
    rep(i, n){
        cin >> p[i];
        p[i]--;
        if(p[i] == -1){
            l++;
        }else if(p[i] % 2){
            ki--;
            if(pre == -1){
                if(l > 0) v.push_back(l);
            }else if(pre == 1){
                if(l > 0) x.push_back(l);
            }else{
                ans++;
            }
            pre = 1;
            l = 0;
        }else{
            gu--;
            if(pre == -1){
                if(l > 0) w.push_back(l);
            }else if(pre == 0){
                if(l > 0) y.push_back(l);
            }else{
                ans++;
            }
            pre = 0;
            l = 0;
        }
    }
    if(l>0){
        if(pre==1){
            if(l > 0) v.push_back(l);
        }else{
            if(l > 0) w.push_back(l);
        }
    }
    sort(all(x));
    sort(all(y));
    sort(all(v));
    sort(all(w));
    ans += 2 * x.size() + 2 * y.size() + v.size() + w.size();
    for(auto &q:x){
        if(ki < q) break;
        ans -= 2;
        ki -= q;
    }
    for(auto &q:v){
        if(ki < q) break;
        ans -= 1;
        ki -= q;
    }
    for(auto &q:y){
        if(gu < q) break;
        ans -= 2;
        gu -= q;
    }
    for(auto &q:w){
        if(gu < q) break;
        ans -= 1;
        gu -= q;
    }
    cout << ans << endl;
    return 0;
}