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

ll gcd(ll x,ll y){
    if(x<y)swap(x,y);
    if(x%y==0)return y;
    return gcd(y,x%y);
}

int main(){
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    ll g=gcd(x,y);
    x/=g;
    y/=g;
    cout<<min(a/x,b/y)<<endl;
    return 0;
}