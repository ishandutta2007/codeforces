#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

int main() {
    scanf("%d%d",&n,&m);
    long long prevd,prevh;
    scanf("%I64d%I64d",&prevd,&prevh);
    long long ans = prevd-1+prevh;
    int ok = 1;
    for (int i=1;i<m;i++) {
        long long nd,nh;
        scanf("%I64d%I64d",&nd,&nh);
        if (abs(nh-prevh)>nd-prevd) ok = 0;
        else ans = max(ans,max(prevh,nh)+((nd-prevd)-abs(nh-prevh))/2);
        prevd = nd; prevh = nh;
    }
    ans = max(ans,prevh+n-prevd);
    if (!ok) printf("IMPOSSIBLE\n");
    else printf("%I64d\n",ans);

    return 0;
}