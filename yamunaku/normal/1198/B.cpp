//
// Created by yamunaku on 2019/07/30.
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
    int n,q;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    cin >> q;
    vi c(q),x(q),y(q);
    rep(i,q){
        cin >> c[i] >> x[i];
        if(c[i]==1) cin >> y[i];
    }
    vi ans(n,-1);
    int v=0;
    per(i,q){
        if(c[i]==1){
            x[i]--;
            if(ans[x[i]]==-1){
                if(y[i]<=v) ans[x[i]]=v;
                else ans[x[i]]=y[i];
            }
        }else{
            v=max(v,x[i]);
        }
    }
    rep(i,n){
        if(ans[i]==-1){
            if(a[i]<=v) ans[i]=v;
            else ans[i]=a[i];
        }
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}