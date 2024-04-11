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


string alph;

void solve(){
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> f(r);
    int num = 0;
    rep(i, r){
        cin >> f[i];
        rep(j, c) if(f[i][j] == 'R') num++;
    }
    int p = num / k, q = num % k;
    int nx=0, ny=-1;
    vector<string> ans(r,string(c,'.'));
    rep(i, k){
        if(i < q) num = p + 1;
        else num = p;
        int tmp=0;
        while(tmp<num){
            if(nx%2){
                if(ny==0) nx++;
                else ny--;
            }else{
                if(ny==c-1) nx++;
                else ny++;
            }
            ans[nx][ny]=alph[i];
            if(f[nx][ny]=='R') tmp++;
        }
    }
    while(1){
        if(nx%2){
            if(ny==0) nx++;
            else ny--;
        }else{
            if(ny==c-1) nx++;
            else ny++;
        }
        if(nx==r) break;
        ans[nx][ny]=alph[k-1];
    }
    rep(i,r) cout << ans[i] << endl;
}

int main(){
    CFS;
    rep(i, 26) alph.push_back('a' + i);
    rep(i, 26) alph.push_back('A' + i);
    rep(i, 10) alph.push_back('0' + i);

    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}