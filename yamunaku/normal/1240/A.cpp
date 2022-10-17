//
// Created by yamunaku on 2019/10/07.
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

int gcd(int x, int y){
    while(x%y){
        int tmp=x%y;
        x=y;
        y=tmp;
    }
    return y;
}

int main(){
    int q;
    cin >> q;
    rep(_,q){
        int n;
        cin >> n;
        vl p(n);
        rep(i,n) cin >> p[i];
        sort(all(p),greater<ll>());
        ll x,a,y,b;
        cin >> x >> a >> y >> b;
        ll k;
        cin >> k;
        int l=0, r=n+1;
        ll total=0;
        while(r-l>1){
            int mid=(l+r)/2;
            int s=mid/(a*b/gcd(a,b));
            int t=mid/a-s;
            int u=mid/b-s;
            int idx=0;
            total=0;
            rep(i,s){
                total+=p[idx]/100*(x+y);
                idx++;
            }
            if(x>y){
                rep(i,t){
                    total+=p[idx]/100*x;
                    idx++;
                }
                rep(i,u){
                    total+=p[idx]/100*y;
                    idx++;
                }
            }else{
                rep(i,u){
                    total+=p[idx]/100*y;
                    idx++;
                }
                rep(i,t){
                    total+=p[idx]/100*x;
                    idx++;
                }
            }
            if(total<k){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(l+1>n){
            cout << -1 << endl;
        }else{
            cout << l+1 << endl;
        }
    }
    return 0;
}