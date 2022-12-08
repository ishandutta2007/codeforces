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
    ll x,y;
    cin>>x>>y;
    if(x>y)swap(x,y);
    if(x==1){
        if(y%6==4)cout<<y-2<<endl;
        else if(y%6==5)cout<<y-1<<endl;
        else cout<<y-(y%6)<<endl;
        return 0;

    }
    if(x==2){
        if(y==2)cout<<0<<endl;
        else if(y==3)cout<<4<<endl;
        else if(y==7)cout<<12<<endl;
        else cout<<2*y<<endl;
        return 0;
    }
    cout<<x*y-(x*y)%2<<endl;
    return 0;
}