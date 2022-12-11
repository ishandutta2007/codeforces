#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("301.inp","r",stdin)
#define OUTPUT freopen("301.out","w",stdout)
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
const int N=1e3+10;

int n,m,lim,sum,L,a[N];
int main(){
    cin>>n>>m>>lim>>sum>>L;
    FOR(i,1,m) cin>>a[i],sum-=a[i];
    int S=0;
    FOR(i,1,m) S+=(a[i]<L);
    if (S>n/2){
        printf("-1");
        return 0;
    }
    int use1,use2;
    if (n-(m-S)<=n/2) use2=0,use1=n-m;
    else use2=(n+1)/2-(m-S),use1=n-m-use2;
    sum-=use1+L*use2;
    if (sum<0) printf("-1");
    else {
        FOR(i,1,use1) printf("1 ");
        FOR(i,1,use2) printf("%d ",L);
    }
}