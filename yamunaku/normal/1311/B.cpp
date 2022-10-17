//
// Created by yamunaku on 2020/02/24.
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
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
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
    int t;
    cin >> t;
    rep(_, t){
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi p(n, false);
        rep(i, n) cin >> a[i];
        int x;
        rep(i, m){
            cin >> x;
            p[x - 1] = true;
        }
        int pre = 0;
        rep(i, n){
            if(!p[i]){
                sort(a.begin() + pre, a.begin() + i + 1);
                pre = i + 1;
            }
        }
        rep(i, n - 1){
            if(a[i] > a[i + 1]){
                CNO;
                goto next;
            }
        }
        CYES;
        next:;
    }
    return 0;
}