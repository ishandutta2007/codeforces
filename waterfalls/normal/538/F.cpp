#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[200013];
int sums[200013];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=2;i<=n;i++) {
        int prev = i-1;
        int num = 1;
        while (prev!=1) {
            int high = (i-2)/(prev-1)+1;
            if (a[i]<a[prev]) sums[num]+=1,sums[high]-=1;
            num = high;
            prev = (i-2+num)/num;
        }
        if (a[i]<a[prev]) sums[num]+=1, sums[n+1]-=1;
    }
    for (int i=2;i<=n;i++) sums[i]+=sums[i-1];
    for (int i=1;i<n;i++) printf("%d ",sums[i]);
    printf("\n");

    return 0;
}