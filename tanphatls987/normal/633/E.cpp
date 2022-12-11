#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,k,a[2][N],g[N];
int smin[N],smax[N],tmin,tmax;
void prepare(){

    scanf("%d%d",&n,&k);
    FOR(i,0,1)
        FOR(j,1,n) scanf("%d",a[i]+j);
}
bool check(int pos){
    int p1=lower_bound(smin,smin+tmin,pos,greater<int>())-smin;
    int p2=lower_bound(smax,smax+tmax,pos,greater<int>())-smax;
    return a[1][smin[p1]]>=100*a[0][smax[p2]];
}
int cal(int pos){
    int p1=lower_bound(smin,smin+tmin,pos,greater<int>())-smin;
    int p2=lower_bound(smax,smax+tmax,pos,greater<int>())-smax;
    return min(a[0][smax[p2]]*100,a[1][smin[p1]]);
}
double solve(){
    a[0][n+1]=inf;
    a[1][n+1]=-inf;
    smin[0]=smax[0]=n+1;
    FORD(i,n,1){
        while (a[0][i]>=a[0][smax[tmax]]) tmax--;
        smax[++tmax]=i;
        while (a[1][i]<=a[1][smin[tmin]]) tmin--;
        smin[++tmin]=i;
        int L=i,R=n;
        while (L<=R){
            int mid=(L+R)/2;
            if (check(mid)) L=mid+1;
            else R=mid-1;
        }
        g[i]=cal(L);
        if (L>i) g[i]=max(g[i],cal(L-1));
//        cout<<i<<" "<<L<<" "<<g[i]<<'\n';
    }
    sort(g+1,g+n+1);
    double ans=0,pro=(k+.0)/n;
    FOR(i,1,n-k+1){
        ans+=pro*g[i];
        pro*=(n-i-k+1.0)/(n-i);
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    printf("%.9f\n",solve());
}