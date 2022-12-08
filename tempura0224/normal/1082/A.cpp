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
    int t;
    cin>>t;
    while(t--){
      int n,x,y,d;
      int ret=2*inf;
      cin>>n>>x>>y>>d;
      if((abs(y-x))%d==0){
        ret=min(ret,(abs(y-x))/d);
      }
      if((y-1)%d==0){
        ret=min(ret,(y-1)/d+(x+d-2)/d);
      }
      if((n-y)%d==0){
        ret=min(ret,(n-y)/d+(n-x+d-1)/d);
      }
      if(ret!=2*inf)cout<<ret<<endl;
      else cout<<-1<<endl;
    }
    return 0;
}