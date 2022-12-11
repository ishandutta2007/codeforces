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
const int N=1e6+10;

double f[2][N];
int n,m;
int main(){
    cin>>n>>m;
    if (m==1){
        printf("1.0000000000000");
        return 0;
    }
    f[0][0]=1;
    int asum=0,x;
    FOR(i,1,n){
        scanf("%d",&x);
        asum+=x;
        int cur=i&1,last=cur^1;
        double sum=0;
        FOR(j,0,m*i){
            if (j) sum=sum+f[last][j-1];
            f[cur][j]=(sum-((j>=x)?f[last][j-x]:0))/(m-1);
            if (j>=m) sum-=f[last][j-m];
//            printf("%d %d %.9f\n",i,j,f[cur][j]);
        }
    }
//    REP(i,0,asum) printf("%.12f ",f[n&1][i]);ENDL;
    double ans=0;
    REP(i,0,asum) ans+=(m-1)*f[n&1][i];
    printf("%.12f",ans+1);
}