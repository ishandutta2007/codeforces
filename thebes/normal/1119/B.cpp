#include <bits/stdc++.h>
using namespace std;

const int MN = 1003;
typedef long long ll;
ll arr[MN], ht[MN], w, n, h, lo, hi, i;

int main(){
    for(scanf("%lld%lld",&n,&h),i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    lo = 1, hi = n+1;
    while(lo<hi){
        ll m = (lo+hi)/2;
        for(i=1;i<=m;i++) ht[i]=arr[i];
        sort(ht+1,ht+m+1,[](ll i,ll j){return i>j;});
        w = 0;
        for(i=1;i<=m;i+=2) w += ht[i];
        if(w<=h) lo=m+1;
        else hi=m;
    }
    printf("%lld\n",lo-1);
    return 0;
}