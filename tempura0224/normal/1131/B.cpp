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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    int ans=1;
    int x=0,y=0;
    int cur=0;
    rep(i,n){
        int nx,ny;
        cin>>nx>>ny;
        if(x==y){
            ans+=min(nx,ny)-x;
        }
        else if(x>y){
            if(nx<=ny)ans+=nx-x+1;
            else ans+=max(ny-x+1,0);
        }
        else{
            if(ny<=nx)ans+=ny-y+1;
            else ans+=max(nx-y+1,0);
        }
        x=nx,y=ny;
    }
    cout<<ans<<endl;
    return 0;
}