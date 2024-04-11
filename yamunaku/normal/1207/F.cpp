//
// Created by yamunaku on 2019/08/22.
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

int main(){
    CFS;
    int q;
    cin >> q;
    int r=sqrt(500000);
    vl a(500001,0);
    mtl v(r,vl(r));
    rep(_,q){
        int c,x,y;
        cin >> c >> x >> y;
        if(c==1){
            a[x]+=y;
            repl(i,1,r){
                v[i][x%i]+=y;
            }
        }else{
            if(x<r){
                cout << v[x][y] << endl;
            }else{
                ll ans=0;
                for(int i=y;i<=500000;i+=x){
                    ans+=a[i];
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}