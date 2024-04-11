#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int A[1000013];
int dp[1000013];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        A[a] = 1;
    }
    for (int i=1000013;i>=0;i--) {
        if (A[i]) {
            dp[i] = 1;
            for (int j=i+i;j<1000013;j+=i) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    printf("%d\n",*max_element(dp,dp+1000013));

    return 0;
}