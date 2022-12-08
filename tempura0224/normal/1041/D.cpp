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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    ll n,h;
    cin>>n>>h;
    ll x1[n],x2[n];
    rep(i,n)cin>>x1[i]>>x2[i];
    ll d[n],a[n+1];
    rep(i,n)d[i]=x1[i+1]-x2[i];
    rep(i,n)a[i+1]=x2[i]-x1[i];
    a[0]=0;
    rep(i,n)a[i+1]+=a[i];
    ll ret=0;
    int r=0;
    ll dist=0;
    rep(i,n){
        while(dist+d[r]<h&&r<n-1){
            dist+=d[r];
            ++r;
        }

        ret=max(ret,a[r+1]-a[i]);
        dist-=d[i];
    }
    cout<<ret+h<<endl;
    return 0;
}