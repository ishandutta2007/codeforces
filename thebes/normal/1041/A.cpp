#include <bits/stdc++.h>
using namespace std;

int mn=1<<30, mx, n, i, x;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        mx = max(mx, x);
        mn = min(mn, x);
    }
    printf("%d\n",mx-mn+1-n);
    return 0;
}