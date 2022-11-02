#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k,p,x,y;

int main() {
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    int numabove = 0;
    int sum = 0;
    for (int i=0;i<k;i++) {
        int a;
        scanf("%d",&a);
        if (a>=y) numabove+=1;
        sum+=a;
    }
    int added = 0;
    while (numabove<=n/2) added+=1, sum+=y, numabove+=1;
    int ok = 1;
    if (added+k>n) ok = 0;
    sum+=n-added-k;
    if (sum>x) ok = 0;
    if (ok) {
        for (int i=0;i<added;i++) printf("%d ",y);
        for (int i=0;i<n-added-k;i++) printf("1 ");
        printf("\n");
    } else printf("-1\n");

    return 0;
}