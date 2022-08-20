#include <bits/stdc++.h>
using namespace std;
int T,n;
pair<int,int> a[1234567];
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i].first),a[i].second=i;
        sort(a+1,a+1+n);
        printf("%d %d\n",a[1].second,a[n].second);
    }
}