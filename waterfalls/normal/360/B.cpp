#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int a[2000];
int best[2000];

bool check(int c) {
    for (int i=0;i<n;i++) {
        best[i] = i;
        for (int j=0;j<i;j++) if (abs(a[i]-a[j])<=(long long) (i-j)*c) best[i] = min(best[i],i-j-1+best[j]);
    }
    for (int i=0;i<n;i++) if (best[i]+n-i-1<=k) return true;
    return false;
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int low = -1;
    int high = 2000000000;
    while (high-low>1) {
        if (check(((long long) low+high+1)/2)) high = ((long long) low+high+1)/2;
        else low = ((long long) low+high+1)/2;
    }
    printf("%d\n",high);

    return 0;
}