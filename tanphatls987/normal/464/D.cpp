#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int M=1e3+10;
const double eps=1e-15;

int n,k;
double f[2][M];
void prepare(){
    scanf("%d%d",&n,&k);
}
double solve(){
    f[0][1]=1;
    double ans=0;
    int st=1,en=1;
    FOR(i,1,n){
        int cur=i&1,last=cur^1;
        while (st<en&&f[last][st]<eps) {
            f[last][st]=f[cur][st]=.0;
            st++;
        }
        while (en<M-1&&f[last][en+1]>eps) en++;
//        cout<<i<<" "<<st<<" "<<en<<" ";
//        printf("%.18f %.18f\n",f[last][1],f[last][en]);
        FOR(j,st,en) ans+=f[last][j]*j*(j+3)/(2*(j+1));
        FOR(j,st,min(en+1,M-1)){
//            f[cur][j]=f[last][j]+f[last][j-1]/(k*j);
            f[cur][j]=f[last][j]*(1-1.0/(k*(j+1)))+f[last][j-1]/(k*j);
        }
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    printf("%.10f\n",solve());
}