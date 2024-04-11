#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[100013];
int has[100013];
long long best[100013];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        has[a[i]]+=1;
    }
    sort(a,a+n);
    best[0] = 0;
    best[-1] = 0;
    for (int i=1;i<=100000;i++) best[i] = max(best[i-1],(long long) i*has[i]+best[i-2]);
    printf("%I64d\n",best[100000]);

    return 0;
}