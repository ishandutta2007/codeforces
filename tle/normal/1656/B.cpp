#include <bits/stdc++.h>
using namespace std;
int T,n,k,a[1234567];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        sort(a+1,a+1+n);
        bool yes=0;
        for(int i=1;i<=n;++i)
            if(binary_search(a+1,a+1+n,a[i]+k)) {
                yes=1;
            }
        puts(yes?"YES":"NO");
    }
}