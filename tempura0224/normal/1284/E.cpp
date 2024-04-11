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



long double v[3030];
int main(){
    ll n;cin>>n;
    vector<ll> a(n),b(n);
    vector<ll> x(n-1),y(n-1);
    rep(i,n)cin>>a[i]>>b[i];
    ll ret = 0;
    vector<int> ord(n-1);
    rep(i,n){
        int k=0;
        rep(j,n){
            if(i==j)continue;
            x[k]=a[j]-a[i];y[k]=b[j]-b[i];
            ++k;
        }
        rep(j,n-1)ord[j]=j;
        rep(j,n-1)v[j]=atan2l(y[j],x[j]);
        sort(ord.begin(),ord.end(),[&](int s,int t){
            return v[s]<v[t];
        });
        ll ans = (n-1)*(n-2)*(n-3)*(n-4)/24;
        k = 1;
        int s = 0;
        for(int id:ord){
            while(x[id]*y[ord[k]]-y[id]*x[ord[k]]>0){
                k++;
                if(k==n-1)k=0;
            }
            ll cnt = k-s;
            if(cnt<=0)cnt += n-1;
            ans -= (cnt-1)*(cnt-2)*(cnt-3)/6;
            ++s;
        }
        ret += ans;
    }
    cout<<ret<<endl;
    return 0;
}