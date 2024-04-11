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
    int n,x,y;
    cin>>n>>x>>y;
    if(x>y){
        cout<<n<<endl;
        return 0;
    }
    int cnt=0;
    rep(i,n){
        int a;
        cin>>a;
        cnt+=(a<=x);
    }
    cout<<(cnt+1)/2<<endl;
    return 0;
}