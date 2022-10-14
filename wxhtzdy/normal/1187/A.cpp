#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        long long n,a,b;
        scanf("%lld %lld %lld",&n,&a,&b);
        long long ans=max(a,b)-(a+b-n)+1;
        printf("%lld\n",ans);
    }
    return 0;
}