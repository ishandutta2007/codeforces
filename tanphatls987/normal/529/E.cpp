#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,k,a[5050],q,x;
ii b[N];
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    b[0]=ii(0,0);
    FOR(i,1,n)
        FOR(j,1,k) b[(i-1)*k+j]=ii(a[i]*j,j);
    sort(b,b+n*k+1);
    int m=0;
    FOR(i,1,n*k){
        b[++m]=b[i];
        while (i<n*k&&b[i+1].X==b[m].X) b[m].Y=min(b[m].Y,b[++i].Y);
    }
    scanf("%d",&q);
    while (q--){
        scanf("%d",&x);
        int ans=k+1;
        for(int i=0,j=m;i<j;i++){
            while (b[i].X+b[j].X>x) j--;
            if (b[i].X+b[j].X==x) ans=min(ans,b[i].Y+b[j].Y);
        }
        if (ans<=k) printf("%d\n",ans);
        else printf("-1\n");
    }
}