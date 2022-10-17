//
// Created by yamunaku on 2019/11/11.
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
    // CFS
    ll n;
    int q;
    cin >> n >> q;
    rep(t, q){
        ll x;
        cin >> x;
        x = 2 * n - 1 - x;
        ll l = 1, r = n + 1;
        while(r - l > 1){
            ll mid = (l + r) / 2;
//            cout << l SP mid SP r << endl;
            mid = n - mid + 1;
            ll tmp = x;
            if(tmp < 2 * mid){
                l = n - mid + 1;
                continue;
            }
            ll k = 1;
            while(tmp > mid << (k+1)){
                k++;
            }
            tmp -= mid << k;
//            cout << x SP mid SP tmp SP k << endl;
            bool ok = true;
            while(k > 0){
                if(tmp % 2 == 0){
                    ok = false;
                    break;
                }
                tmp /= 2;
                k--;
            }
            if(ok){
                l = n - mid + 1;
            }else{
                r = n - mid + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}