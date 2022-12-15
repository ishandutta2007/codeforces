#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
long long ans, psa[MN];
int n, i, arr[MN];

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+n+1);
    for(i=1;i<n;i++){
        ans += 1LL*(i+1)*arr[i];
    }
    ans += 1LL*n*arr[n];
    printf("%lld\n",ans);
    return 0;
}