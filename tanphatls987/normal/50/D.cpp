#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e2+10;
const double eps=1e-9;

double f[N];
int n,m,per,rx,ry,x,y,d[N];
int sqr(int x){
    return x*x;
}
int dist(ii a,ii b){
    return sqr(a.X-b.X)+sqr(a.Y-b.Y);
}
double check(double M){
    f[0]=1;
    FOR(i,1,n) f[i]=.0;
    FOR(i,1,n){
        double prob=(M*M>=d[i])?1.0:((abs(M)<eps)?0:exp(1-(d[i]+.0)/(M*M)));
        FORD(j,i,1) f[j]=prob*f[j-1]+(1.0-prob)*f[j];
        f[0]*=(1-prob);
    }
//    FOR(i,0,n) printf("%.10f ",f[i]);ENDL;
    FOR(i,1,m) f[i]+=f[i-1];
    //printf("%.10f\")
    return f[m]*1000<=per;
}
int main(){
//    INPUT;OUTPUT;
    scanf("%d%d%d%d%d",&n,&m,&per,&rx,&ry);
    m--;
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        d[i]=dist(ii(x,y),ii(rx,ry));
    }
    double L=.0,R=1e5;
    FOR(i,1,100){
        double M=(L+R)/2;
//        printf("%.10f %.10f %.10f\n",L,R,M);
        if (check(M)) R=M;
        else L=M;
    }
    printf("%.10f\n",L);
}