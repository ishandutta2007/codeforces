#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int arr[MN], n, s, i;
long long ans;

int main(){
    for(scanf("%d%d",&n,&s),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+n+1);
    for(i=1;i<=n/2;i++)
        ans+=max(0,arr[i]-s);
    ans += abs(arr[n/2+1]-s);
    for(i=n;i>n/2+1;i--)
        ans+=max(0,s-arr[i]);
    printf("%lld\n",ans);
    return 0;
}