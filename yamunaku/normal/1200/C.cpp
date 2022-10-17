//
// Created by yamunaku on 2019/08/11.
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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

ll gcd(ll x,ll y){
    while(x%y){
        ll tmp=x%y;
        x=y;
        y=tmp;
    }
    return y;
}

int main(){
    ll n,m,q;
    cin >> n >> m >> q;
    ll g=gcd(n,m);
    rep(_,q){
        ll sx,sy,gx,gy;
        cin >> sx >> sy >> gx >> gy;
        ll sr, gr;
        sy--,gy--;
        if(sx==1){
            sr=sy/(n/g);
        }else{
            sr=sy/(m/g);
        }
        if(gx==1){
            gr=gy/(n/g);
        }else{
            gr=gy/(m/g);
        }
        if(sr==gr){
            CYES;
        }else{
            CNO;
        }
    }
    return 0;
}