#include<bits/stdc++.h>
using namespace std;
const int N=4e4+10;
long long t,n,a[N],sum,b[N];
int main(){
    scanf("%lld",&t);
    while(t--){
        sum=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        if(sum%((n+1)*n/2)!=0){
            puts("No");
            continue;
        }
        sum/=((n+1)*n/2);
        int pd=0;
        for(int i=1;i<=n;i++){
            b[i]=(sum-a[i]+a[(i-2+n)%n+1])/(n);
            pd|=((b[i]<=0)|((sum-a[i]+a[(i-2+n)%n+1])%(n)!=0));
        }
        if(pd){puts("NO");continue;}
        puts("YES");
        for(int i=1;i<=n;i++){
            printf("%lld ",b[i]);
        }
        puts("");
    }
    return  0;
}