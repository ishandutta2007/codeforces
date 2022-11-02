#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n,k,q;
int a[5000];
set<int> amounts;

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) amounts.insert(a[i]);
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        int x;
        scanf("%d",&x);
        int ans = 1000000000;
        for (int j=0;j<n;j++) {
            for (int num=1;num<=k && a[j]*num<=x;num++) {
                int left = x-num*a[j];
                if (left==0) ans = min(ans,num);
                if (left<0) continue;
                for (int other=1;num+other<=k;other++) {
                    if (left%other==0 && amounts.count(left/other)) ans = min(ans,num+other);
                }
            }
        }
        if (ans==1000000000) printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}