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
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        rep(i,n)a[i]/=100;
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        ll x,u,y,v;
        cin>>x>>u;
        cin>>y>>v;
        ll k;
        cin>>k;
        ll ok=n+1, ng=0;
        while(ok-ng>1){
            int mid= (ok+ng)/2;
            ll cnt0=0,cnt1=0,cnt2=0;
            REP(i,1,mid+1){
                if(i%u==0&&i%v==0)++cnt0;
                else if(i%u==0)++cnt1;
                else if(i%v==0)++cnt2;
            }
            ll ret1=0, ret2=0;
            rep(i,cnt0+cnt1+cnt2){
                if(i<cnt0){
                    ret1+=(x+y)*a[i];
                    ret2+=(x+y)*a[i];
                }
                else {
                    if(i<cnt0+cnt1)ret1+=x*a[i];
                    else ret1+=y*a[i];
                    if(i<cnt0+cnt2)ret2+=y*a[i];
                    else ret2+=x*a[i];
                }
            }
            if(max(ret1,ret2)>=k)ok=mid;
            else ng=mid;
        }
        if(ok==n+1)printf("-1\n");
        else printf("%lld\n",ok);
    }
    
    return 0;
}