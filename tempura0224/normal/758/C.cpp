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
    ll n,m,k,x,y;
    cin>>n>>m>>k>>x>>y;
    if(n==1){
        cout<<(k+m-1)/m<<" ";
        cout<<k/m<<" ";
        if(k%m>=y)cout<<(k+m-1)/m<<" ";
        else cout<<k/m<<" ";
        return 0;
    }
    --x;--y;
    ll ma=0,mi=longinf;
    ll r=2*n-2;
    ll t=k/(r*m);
    k-=t*r*m;
    ll ret[n][m];
    rep(i,n)rep(j,m){
        if(i==0||i==n-1)ret[i][j]=t;
        else ret[i][j]=2*t;
    }
    int i=0,j=0;
    while(k--){
        ++ret[min((ll)i,2*n-2-i)][j];
        if(j==m-1){
            j=0;
            ++i;
        }
        else ++j;
    }
    rep(i,n)rep(j,m){
        ma=max(ma,ret[i][j]);
        mi=min(mi,ret[i][j]);
    }
    cout<<ma<<" "<<mi<<" "<<ret[x][y]<<endl;
    return 0;
}