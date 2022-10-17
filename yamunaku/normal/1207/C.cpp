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
    int t;
    cin >> t;
    rep(_,t){
        ll n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        ll x=0,y=LINF,nx,ny;
        rep(i,n){
            nx=LINF;
            ny=min(x+a+b,y)+b;
            if(s[i]=='0'){
                nx=min(x,y+a);
            }
            x=nx,y=ny;
        }
        cout << x+n*(a+b)+b << endl;
    }
    return 0;
}