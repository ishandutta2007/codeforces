#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e3+5;

double f[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    f[0][0]=1;
    REP(i,0,n){
        FOR(j,0,i) f[i+1][j]=f[i][j]*((n-1)*m-(i-j))/(n*m-i);
        FOR(j,1,i+1) f[i+1][j]+=f[i][j-1]*(m-j+1)/(n*m-i);
    }
//    FOR(i,1,n)
//        FOR(j,0,n) printf("%d %d %.9f\n",i,j,f[i][j]);
    double ans=0;
    FOR(i,1,n) ans+=f[n][i]*i*i/n;
    printf("%.9f\n",ans);
}