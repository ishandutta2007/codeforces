#include <bits/stdc++.h>
using namespace std;

int n, k, i, a[105], mx, w;

int main(){
        for(scanf("%d",&n),i=1;i<=n;i++)
                scanf("%d",&a[i]), mx = max(mx, a[i]);
        for(k=mx;;k++){
                w = 0;
                for(i=1;i<=n;i++)
                        w += k-2*a[i];
                if(w>0) break;
        }
        printf("%d\n",k);
        return 0;

}