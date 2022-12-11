#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=4e3+10;

int n,x,y,a[N];

int main(){
    scanf("%d\n",&n);
    FOR(i,1,n<<1){
        scanf("%d.%d ",&x,&y);
        a[i]=y;
    }
    sort(a+1,a+2*n+1);
    int st=0,sum=0;
    while (st<2*n&&!a[st+1]) st++;
    FOR(i,st+1,2*n) sum+=a[i];
    int ans=inf;
    FOR(i,0,n-max(st-n,0)) if (st>=n-i)
        ans=min(ans,abs(1000*i-sum));
    printf("%.3f",(ans+.0)/1000);
}