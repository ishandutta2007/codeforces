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
const int N=2e3+10;

int n,k,a[N],f[N][N];
bool check(int M){
    f[1][0]=0;
    f[1][1]=1;
    FOR(i,2,n){
        FOR(j,0,min(i,k)) f[i][j]=k+1;
        FOR(j,0,min(i-1,k)){
            if (i-1==j||abs(a[i]-a[i-j-1])<=1LL*M*(j+1)) f[i][0]=min(f[i][0],f[i-1][j]);
            f[i][j+1]=min(f[i][j+1],f[i-1][j]+1);
        }
    }
//    cout<<M<<'\n';
//    FOR(i,2,n)
//        FOR(j,0,min(i,k)) printf("%d %d %d\n",i,j,f[i][j]);
    return *min_element(f[n],f[n]+k+1)<=k;
}
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    int L=0,R=inf<<1;
    while (L<=R){
        int M=L+(R-L)/2;
        if (check(M)) R=M-1;
        else L=M+1;
    }
    cout<<L;
}