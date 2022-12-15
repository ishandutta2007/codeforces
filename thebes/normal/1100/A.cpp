#include <bits/stdc++.h>
using namespace std;

int a, c, n, i, j, ans=0, b, k, arr[105];

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        c += arr[i];
    }
    for(i=1;i<=min(k,n);i++){
        a = c;
        for(j=0;j*k+i<=n;j++){
            a -= arr[j*k+i];
        }
        ans = max(ans, abs(a));
    }
    printf("%d\n",ans);
    return 0;
}