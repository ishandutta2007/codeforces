#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10,M=2e4;

int n,a[N];
bool minimize(int &x,int y){
    if (x>y) x=y;else return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    REP(i,0,n) scanf("%d",a+i);
    sort(a,a+n);
    int ans=inf,ansv,anst;
    FOR(step,0,M){
        int mi=inf,ma=-inf;
        REP(i,0,n) {
            mi=min(mi,a[i]-step*i);
            ma=max(ma,a[i]-step*i);
        }
//        printf("%d %d %d\n",step,mi,ma);
        int use=(ma-mi+1)>>1;
        if (minimize(ans,use)) ansv=mi+use,anst=step;
    }
    printf("%d\n%d %d",ans,ansv,anst);
}