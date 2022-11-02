#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k,q;
int a[5000];
bool amounts[10000013];

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) amounts[a[i]] = 1;
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
                    if (left%other==0 && left/other<=10000000 && amounts[left/other]) ans = min(ans,num+other);
                }
            }
        }
        if (ans==1000000000) printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}