//
// Created by yamunaku on 2019/12/29.
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
    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << "! 1" << endl;
        return 0;
    }
    int p, v;
    cout << "?";
    rep(i, k) cout << " " << i + 1;
    cout << endl;
    cin >> p >> v;
    p--;
    int np, nv;
    cout << "?";
    rep(i, k + 1) if(i != p) cout << " " << i + 1;
    cout << endl;
    cin >> np >> nv;
    np--;
    if(v > nv) swap(p, np);
    int c = 0;
    int nnp;
    rep(i, k + 1){
        if(i == p || i == np) continue;
        cout << "?";
        rep(j, k + 1) if(j != i) cout << " " << j + 1;
        cout << endl;
        cin >> nnp >> nv;
        nnp--;
        if(nnp != p){
            c++;
        }
    }
    cout << "! " << c + 1 << endl;
    return 0;
}