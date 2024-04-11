#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
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
#define inf 1000000

const int MOD=1000000007;
const int N=100010;

typedef long long ll;

int n;
ll m,tem,t,c,cost;
void prepare(){
    scanf("%d%I64d",&n,&m);
    ll ans=0;
    FOR(i,1,n){
        scanf("%I64d%I64d%I64d%I64d",&tem,&t,&c,&cost);
        if (t<=tem) {ans+=cost+m*c;continue;}
        ll car=(m+t-tem-1)/(t-tem);
        /*
        if ((t-tem)*c>cost){
            ll per=m-(t-tem);
            if (per<=0) pri=cost;else
            if (per<=t-tem) pri=min(cost+m*c,2*cost);else
                pri=min((car-1)*cost+(m-(car-2)*(t-tem))*c,car*cost);
        }else pri=cost+c*m;
        ans+=pri;*/
        if (car<=1) ans+=cost;else
        ans+=min(cost+m*c,min((car-1)*cost+(m-(car-2)*(t-tem))*c,car*cost));
    }
    cout<<ans;
}
int main(){
    prepare();
}