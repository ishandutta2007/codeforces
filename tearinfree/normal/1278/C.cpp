#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n,a[100001],b[100001],c[200001];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        fill(c,c+MAX+MAX+1, MAX+MAX);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=1;i<=n;i++) scanf("%d",b+i);
        for(int i=1;i<=n;i++) if(a[i]==2) a[i] = -1;
        for(int i=1;i<=n;i++) if(b[i]==2) b[i] = -1;
        reverse(b+1,b+n+1);
        
        c[MAX] = n;
        for(int i=1;i<=n;i++) {
            a[i] += a[i-1];
            c[a[i] + MAX] = n-i;
        }

        int ans = min(2*n, n + c[MAX]);
        for(int i=1;i<=n;i++) {
            b[i] += b[i-1];
            ans = min(ans, n-i + c[MAX - b[i]]);
        }
        if(a[n] == 0 || b[n] == 0) ans = min(ans, n);
        printf("%d\n",ans);
    }
    return 0;
}