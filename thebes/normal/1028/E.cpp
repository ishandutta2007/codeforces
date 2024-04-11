#include <bits/stdc++.h>
using namespace std;

const int MN=2e5+5;
long long arr[MN], ans[MN], n, i, x, flag;
inline long long ls(long long idx){return (idx+n-2)%n+1;}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        if(arr[i]) flag=i;
    }
    if(!flag){
        printf("YES\n");
        for(i=1;i<=n;i++) printf("1 ");
    }
    else{
        flag = 0;
        for(i=1;i<=n;i++)
            if(arr[i]>arr[(i+n-2)%n+1]&&arr[i]) flag=i;
        if(!flag){
            printf("NO\n");
            return 0;
        }
        ans[flag] = arr[flag];
        x = arr[flag];
        for(i=ls(flag);i!=flag;i=ls(i)){
            long long mul = max(1LL,(long long)ceil((arr[ls(i)]+1-arr[i])/(double)x));
            x = x*mul+arr[i]; ans[i] = x;
        }
        printf("YES\n");
        for(i=1;i<=n;i++)
            printf("%lld ",ans[i]);
    }
    return 0;
}