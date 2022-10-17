//
// Created by yamunaku on 2020/08/16.
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
    int n;
    cin >> n;
    mtl a(n + 1, vl(n + 1));
    int k = (n + 1) / 2;
    rep(i, k){
        rep(j, k){
            a[2 * i][2 * j] = 0;
            a[2 * i][2 * j + 1] = 0;
            a[2 * i + 1][2 * j] = 1ll << (i + i + j + j);
            a[2 * i + 1][2 * j + 1] = 2ll << (i + i + j + j);
        }
    }
    rep(i, n){
        rep(j, n){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    rep(_, q){
        ll s = 0;
        cin >> s;
        int nx = 0, ny = 0;
        int m = 0;
        rep(i, 2 * n - 1){
            cout << nx + 1 SP ny + 1 << endl;
            if(m == 0){
                if(s & 1){
                    nx++;
                    m = 1;
                }else{
                    ny++;
                }
            }else{
                if(s & 1){
                    ny++;
                }else{
                    nx++;
                    m = 0;
                }
            }
            s >>= 1;
        }
    }
    return 0;
}