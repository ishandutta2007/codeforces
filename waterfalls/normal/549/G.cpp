#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int a[200013];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]), a[i]-=n-1-i;
    sort(a,a+n);
    for (int i=0;i<n;i++) a[i]+=n-1-i;
    int ok = 1;
    for (int i=0;i<n-1;i++) if (a[i]>a[i+1]) ok = 0;
    if (!ok) printf(":(");
    else for (int i=0;i<n;i++) printf("%d ",a[i]);

    return 0;
}