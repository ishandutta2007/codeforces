#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("H.inp","r",stdin)
#define OUTPUT freopen("H.out","w",stdout)
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
const int N=0;
const long double eps=1e-18;

int a[2][2];
long double f[2][2][2],r[2][2];
bool cross(long double L1,long double R1,long double L2,long double R2){
    if (L1>=R2+eps||L2>=R1+eps) return 0;
    return 1;
}
bool check(long double M){
    FOR(i,0,1)
        FOR(j,0,1){
        f[i][j][0]=a[i][j]-M;
        f[i][j][1]=a[i][j]+M;
    }
    FOR(i,0,1){
        r[i][0]=4e18,r[i][1]=-4e18;
        FOR(j,0,1)
            FOR(k,0,1){
                long double tmp=(f[i][0][j]*f[i][1][k]);
                r[i][0]=min(r[i][0],tmp);
                r[i][1]=max(r[i][1],tmp);
            }
    }
    //printf("%.9f %.9f %.9f %.9f\n",r[0][0],r[0][1],r[1][0],r[1][1]);
    return cross(r[0][0],r[0][1],r[1][0],r[1][1]);
}
int main(){
    scanf("%d%d%d%d",&a[0][0],&a[1][0],&a[1][1],&a[0][1]);
    long double L=0,R=2e9+5;
    FOR(t,1,1000){
        long double M=(L+R)/2;
        if (check(M)) R=M-eps;
        else L=M+eps;
    }
    //cout<<L<<'\n';
    printf("%.10f",double(L));
    //cout<<check(L);
}