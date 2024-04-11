#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int l = -100000, r = 100000, u = 100000, d = -100000;
        rep(i,n){
            int x,y;
            cin>>x>>y;
            int t;
            cin>>t;if(!t)l=max(l,x);
            cin>>t;if(!t)u=min(u,y);
            cin>>t;if(!t)r=min(r,x);
            cin>>t;if(!t)d=max(d,y);
        }
        if(l>r||d>u)cout<<0<<"\n";
        else cout<<1<<" "<<l<<" "<<d<<"\n";
    }
    return 0;
}