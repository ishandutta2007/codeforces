#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int h[100013];
int l[100013];
int r[100013];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&h[i]);
        l[i] = 1e9;
        r[i] = 1e9;
    }
    int cur = 1e9;
    for (int i=0;i<=n;i++) {
        cur = min(cur,h[i]-i);
        l[i] = min(l[i],i+cur);
    }
    cur = 1e9;
    for (int i=n+1;i>=1;i--) {
        cur = min(cur,h[i]+i);
        r[i] = min(r[i],cur-i);
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        int w = min(l[i],r[i]);
        ans = max(ans,w);
    }
    printf("%d\n",ans);

    return 0;
}