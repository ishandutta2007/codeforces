#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","r",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e3+10;

struct point{
    int x,y,t;
    double pro;
}a[N];
int n;
double f[N];
bool comp(point a,point b){
    return a.t<b.t;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d%lf",&a[i].x,&a[i].y,&a[i].t,&a[i].pro);
    sort(a+1,a+n+1,comp);
}
int main(){
    prepare();
    FOR(i,1,n){
        f[i]=.0;
        REP(j,1,i){
            ll dis=1LL*(a[i].t-a[j].t)*(a[i].t-a[j].t);
            int dx=abs(a[i].x-a[j].x),dy=abs(a[i].y-a[j].y);
            if (dx*dx+dy*dy<=dis) f[i]=max(f[i],f[j]);
        }
        f[i]+=a[i].pro;
        //if (debug) printf("%d %.6f %.6f\n",i,a[i].pro,f[i]);
    }
    printf("%.7f",*max_element(f+1,f+n+1));
}