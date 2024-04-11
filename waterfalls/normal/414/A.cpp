#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;

int main() {
    scanf("%d%d",&n,&k);
    if (k==0 && n==1) printf("1\n");
    else if (k==0 || k<n/2 || (n<2 && k>0)) printf("-1\n");
    else {
        int extra = n/2-1;
        int first = k-extra;
        printf("%d %d ",first,2*first);
        for (int i=0;i<n-2;i++) printf("%d ",800000000+i);
        printf("\n");
    }

    return 0;
}