#include <cstdio>
#include <algorithm>

using namespace std;

int a[2013];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) {
        int ans = 0;
        for (int j=0;j<n;j++) if (a[j]>a[i]) ans+=1;
        printf("%d ",ans+1);
    }
    printf("\n");

    return 0;
}