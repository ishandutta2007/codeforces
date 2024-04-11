#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long A,B;
int n;

int main() {
    scanf("%I64d%I64d%d",&A,&B,&n);
    for (int i=0;i<n;i++) {
        int l,t,m;
        scanf("%d%d%d",&l,&t,&m);
        if (A+B*(l-1)>t) {
            printf("-1\n");
            continue;
        }
        int low = 0;
        int high = 10000000;
        while (high-low>1) {
            int mid = (low+high)/2;
            long long last = A+(l-1)*B+mid*B;
            long long sum = (mid+1)*(A+(l-1)*B+last)/2;
            long long turns = max(last,(sum+m-1)/m);
            if (turns>t) high = mid;
            else low = mid;
        }
        printf("%d\n",low+l);
    }

    return 0;
}