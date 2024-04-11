#include <bits/stdc++.h>

using namespace std;

const long long inf=6e18;
const int N=2e5+10;


int need,cost,bud,n,m;
int a[N][2];
int w[N],c[N];

long long solve(){
    long long ans=inf;
    for(int i=0;i<=n;i++) if (a[i][1]<=bud){
        int use=w[upper_bound(c+1,c+m+1,bud-a[i][1])-c-1];
        ans=min(ans,1LL*max(0,need-use)*a[i][0]);
    }
    return ans;
}
int main(){
    scanf("%d%d%d%d%d",&need,&n,&m,a[0],&bud);
    for(int i=1;i<=n;i++) scanf("%d",a[i]);
    for(int i=1;i<=n;i++) scanf("%d",a[i]+1);
    for(int i=1;i<=m;i++) scanf("%d",w+i);
    for(int i=1;i<=m;i++) scanf("%d",c+i);
    printf("%lld",solve());
}