#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        long long a,b,x,y,n;
        scanf("%lld %lld %lld %lld %lld",&a,&b,&x,&y,&n);
        long long ka=a-x,kb=b-y;
        if((ka+kb)<=n){
            printf("%lld\n",x*y);
            continue;
        }
        if(a-min(n,ka)<=b-min(n,kb)){
            long long h=min(n,ka);
            a-=h,n-=h,b-=min(n,kb);
        }else{
            long long h=min(n,kb);
            b-=h,n-=h,a-=min(n,ka);
        }
        printf("%lld\n",a*b);
    }
    return 0;
}