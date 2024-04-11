#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
    scanf("%lld",&t);
    while(t--){
        long long ans=0;
        for(long long i=2;i<=1ll<<30;i<<=1){
            printf("? %lld %lld\n",((i>>1)-ans),((i>>1)-ans)+i);
            fflush(stdout);
            long long d;
            scanf("%lld",&d);
            if(d==i)ans|=i>>1;
        }
        printf("! %lld\n",ans);
            fflush(stdout);
    }
    return  0;
}