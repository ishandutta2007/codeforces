#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef double lfl;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;
const double eps=0.000000001;

int main()
{   ll y1,y2,yw,xb,yb,r;
    cin>>y1>>y2>>yw>>xb>>yb>>r;
    //lfl e=sqrt((y2-y1-r)*(y2-y1-r)-(r*r));
    lfl ans;
    if (yb<y1+r){
        ll tmp=y1+r-yb;
        ans=((lfl(.0+xb))*(yw-2*r-y1))/(2*(yw-2*r-y1)+tmp);
    }
    else{
        ll tmp=yb-y1-r;
        ans=((lfl(.0-xb))*(yw-2*r-y1))/(-2*(yw-2*r-y1)+tmp);
    }
    lfl e=sqrt(ans*ans+(yw-2*r-y1)*(yw-2*r-y1));
    lfl check=(ans*(y2-r-y1))/e;
    //printf("%.12f %.12f ",e,check);
    if (check<r) printf("-1");
    else printf("%.12f",ans);
}