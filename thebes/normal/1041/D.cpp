#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, h, psa[MN], i, x, ans, lo, hi;
pair<int,int> arr[MN];

int main(){
    for(scanf("%d%d",&n,&h),i=1;i<=n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr+1,arr+n+1);
    for(i=2;i<=n;i++)
        psa[i]=psa[i-1]+arr[i].first-arr[i-1].second;
    for(i=1;i<=n;i++){
        lo = i, hi = n+1;
        while(lo < hi){
            int m = lo+hi>>1;
            if(psa[m]-psa[i]>=h) hi=m;
            else lo=m+1;
        }
        lo--;
        int r = h-(psa[lo]-psa[i]);
        ans=max(ans,arr[lo].second-arr[i].first+r);
    }
    printf("%d\n",ans);
    return 0;
}