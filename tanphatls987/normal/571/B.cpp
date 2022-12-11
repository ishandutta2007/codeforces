#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int M=3e5+10,N=5e3+10;

int n,k,a[M],f[N][N];
int main(){
    scanf("%d%d",&n,&k);
    REP(i,0,n) scanf("%d",a+i);
    sort(a,a+n,greater<int>());
//    cout<<"tick";
    int m1=n%k,m2=k-m1,len=n/k+1;
    f[0][0]=0;
    FOR(i,0,m1)
        FOR(j,0,m2){
            if (!(i+j)) continue;
            f[i][j]=inf;
//            printf("%d %d\n",i,j);
            if (i) {
                int st=(i-1)*len+j*(len-1);
                f[i][j]=min(f[i][j],f[i-1][j]+a[st]-a[st+len-1]);
            }
            if (j){
                int st=i*len+(j-1)*(len-1);
                f[i][j]=min(f[i][j],f[i][j-1]+a[st]-a[st+len-2]);
            }
        }
    cout<<f[m1][m2];
}