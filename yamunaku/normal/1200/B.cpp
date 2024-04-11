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
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
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
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> h(n);
        rep(i,n){
            cin >> h[i];
        }
        ll sum=m;
        bool ok=true;
        rep(i,n-1){
            if(h[i]+k>=h[i+1]){
                sum+=h[i]-max(0ll,h[i+1]-k);
            }else{
                if(h[i]+k+sum>=h[i+1]){
                    sum-=h[i+1]-(h[i]+k);
                }else{
                    ok=false;
                    break;
                }
            }
        }
        if(ok) CYES;
        else CNO;
    }
    return 0;
}