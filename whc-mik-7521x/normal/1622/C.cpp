#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n;
long long k,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        long long mi=1e18,now=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            mi=min(a[i],mi);
            now+=a[i];
        }
        sort(a+1,a+n+1,[](long long b1,long long b2){return b1>b2;});
        if(now<=k){
            puts("0");
            continue;
        }
        if(n==1){
            printf("%lld\n",max(0ll,mi-k));
            continue;
        }
        long long ans=now-k,cnt=0;
        for(int i=1;i<n;i++){
            cnt+=a[i]-mi;
            long long na=(now-cnt>=k?((now-cnt-k)%(i+1)==0?(now-cnt-k)/(i+1):(now-cnt-k)/(i+1)+1):0)+i;
            ans=min(ans,na);
        }
        printf("%lld\n",ans);
    }
    return  0;
}