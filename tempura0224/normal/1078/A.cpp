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
    double a,b,c;
    cin>>a>>b>>c;
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double ans=abs(x2-x1)+abs(y2-y1);
    if(a!=0&&b!=0){
        double x3=(-b*y1-c)/a;
        double x4=(-b*y2-c)/a;
        double ret=abs(x3-x1)+abs(x4-x2)+sqrt((x3-x4)*(x3-x4)+(y1-y2)*(y1-y2));
        ans=min(ans,ret);
        double y3=(-a*x1-c)/b;
        double y4=(-a*x2-c)/b;
        ret=abs(y3-y1)+abs(y4-y2)+sqrt((y3-y4)*(y3-y4)+(x1-x2)*(x1-x2));
        ans=min(ans,ret);
        ret=abs(x3-x1)+abs(y4-y2)+sqrt((x3-x2)*(x3-x2)+(y1-y4)*(y1-y4));
        ans=min(ans,ret);
        ret=abs(y3-y1)+abs(x4-x2)+sqrt((x1-x4)*(x1-x4)+(y3-y2)*(y3-y2));
        ans=min(ans,ret);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}