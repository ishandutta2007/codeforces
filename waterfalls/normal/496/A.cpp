#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int holds[n];
    for (int i=0;i<n;i++) scanf("%d",&holds[i]);
    int ans = 10000;
    for (int i=1;i<n-1;i++) {
        int prev = holds[0];
        int cur = 0;
        for (int j=1;j<n;j++) {
            if (j!=i) {
                cur = max(cur,holds[j]-prev);
                prev = holds[j];
            }
        }
        ans = min(ans,cur);
    }
    printf("%d\n",ans);

    return 0;
}