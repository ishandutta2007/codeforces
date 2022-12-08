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
    int n;cin>>n;
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    c-=a;e-=a;d-=b;f-=b;
    if(c*e>0&&d*f>0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}