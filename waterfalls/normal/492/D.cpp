#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long x,y;
    scanf("%d%I64d%I64d",&n,&x,&y);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        long long low = 0;
        long long high = max(x,y)*a;
        while (high-low>1) {
            long long mid = (low+high)/2;
            if (mid/x+mid/y>=a) high = mid;
            else low = mid;
        }
        if (high%y<high%x) printf("Vanya\n");
        if (high%y>high%x) printf("Vova\n");
        if (high%y==high%x) printf("Both\n");
    }

    return 0;
}