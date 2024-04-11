#include <bits/stdc++.h>
using namespace std;
int T,n,k,a[1234567];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        bool a1=0,c1=0;
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),a1|=a[i]==1;
        sort(a+1,a+1+n);
        for(int i=1;i<n;++i)
            c1|=a[i+1]==a[i]+1;
        if(a1&&c1) puts("NO");
        else puts("YES");
    }
}