#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int main(){
        scanf("%d%d",&n,&k);
        ans += (int)ceil(2.0*n/(double)k);
        ans += (int)ceil(5.0*n/(double)k);
        ans += (int)ceil(8.0*n/(double)k);
        printf("%d\n",ans);
        return 0;
}