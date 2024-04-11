#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long A;
long long d[200013];

int main() {
    scanf("%d%I64d",&n,&A);
    for (int i=0;i<n;i++) scanf("%I64d",&d[i]);
    long long maxSum = 0;
    for (int i=0;i<n;i++) maxSum+=d[i];
    long long minSum = n;
    for (int i=0;i<n;i++) {
        long long lower = max(A-(maxSum-d[i]),1LL);
        long long upper = min(A-(minSum-1),d[i]);
        printf("%I64d ",d[i]-(upper-lower+1));
    }
    printf("\n");

    return 0;
}