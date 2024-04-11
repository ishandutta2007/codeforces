#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a,b;



signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&a,&b);
        if(a==1){
            if((n-1)%b==0) printf("Yes\n");
            else printf("No\n");
            continue;
        }
        int t=1,ok=0;
        while(t<=n){
            if((n-t)%b==0){
                ok=1;
                break;
            }
            t*=a;
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}