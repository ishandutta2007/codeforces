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
const int N=2e3+10;

int n,hei,fr[N],fl[N],a[N];
double pro,g[N][N][2][2];
void prepare(){
    scanf("%d%d%lf",&n,&hei,&pro);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    a[n+1]=inf;
    a[0]=-inf;
    FORD(i,n,1) fr[i]=a[i+1]-a[i]<hei?fr[i+1]:i;
    FOR(i,1,n) fl[i]=a[i]-a[i-1]<hei?fl[i-1]:i;
//    FOR(i,1,n) cout<<fl[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<fr[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
}
int rcover(int x,int y,int type){
    if (!type) return min(hei,a[y]-hei-a[x]);
    return min(hei,a[y]-a[x]);
}
int lcover(int x,int y,int type){
    if (type) return rcover(x,y,0);
    return rcover(x,y,1);
}
double solve(){
    g[1][n][0][1]=1.0;
    double ans=0;
//    printf("%.6f %.6f\n",pro,1-pro);
    FORD(R,n,1)
        FOR(L,1,R){
            ///left tree
            ///right fall
            int nL=min(R,fr[L]);
            FOR(type,0,1){
                double sum=g[L][R][0][type]+g[L][R][1][type];
                ans+=0.5*sum*(1-pro)*(a[nL]-a[L]+rcover(nL,nL+1,(nL==R)?type:1));
                g[nL+1][R][1][type]+=0.5*(1-pro)*sum;
            }
            ///left fall
            FOR(typef,0,1)
                FOR(type,0,1){
                    ans+=0.5*g[L][R][typef][type]*pro*lcover(L-1,L,typef);
                    g[L+1][R][0][type]+=0.5*pro*g[L][R][typef][type];
                }
            ///right tree
            int nR=max(L,fl[R]);
            FOR(type,0,1){
                double  sum=g[L][R][type][0]+g[L][R][type][1];
                ans+=0.5*sum*pro*(a[R]-a[nR]+lcover(nR-1,nR,(nR==L)?type:0));
                g[L][nR-1][type][0]+=sum*0.5*pro;
            }
            FOR(typef,0,1)
                FOR(type,0,1){
                    ans+=0.5*g[L][R][type][typef]*(1-pro)*rcover(R,R+1,typef);
                    g[L][R-1][type][1]+=0.5*(1-pro)*g[L][R][type][typef];
                }
        }
    return ans;
}
int main(){
    prepare();
    printf("%.10f",solve());
}