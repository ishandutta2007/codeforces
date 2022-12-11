#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int n,q,mod,a[N],fib[N],cnt;
signed main(){
    scanf("%lld%lld%lld",&n,&q,&mod);
    fib[1]=fib[2]=1%mod;
    for(int i=3;i<N;i++){
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%lld",&x);
        a[i]-=x;
    }
    for(int i=n;i>=2;i--)a[i]=((a[i]-a[i-1]-a[i-2])%mod+mod)%mod;
    for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
    while(q--){
        char s;
        int l,r,kk;
        scanf("\n%c%lld%lld",&s,&l,&r);
        if(s=='A')kk=1;
        else kk=-1;
        cnt-=a[l]==0;
        a[l]=((a[l]+kk*1)%mod+mod)%mod;
        cnt+=a[l]==0;
        if(r+1<=n){
            cnt-=a[r+1]==0;
            a[r+1]=((a[r+1]-kk*fib[r-l]-kk*fib[r-l+1])%mod+mod)%mod;
            cnt+=a[r+1]==0;
        }
        if(r+2<=n){
            cnt-=a[r+2]==0;
            a[r+2]=((a[r+2]-kk*fib[r-l+1])%mod+mod)%mod;
            cnt+=a[r+2]==0;
        }
        puts(cnt==n?"YES":"NO");
    }
    return  0;
}