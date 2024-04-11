#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+9;
int n;

int main(){
    scanf("%d",&n);n/=2;
    ll tmp=1,ans=0,p=2;
    for(int i=2;i<=n;i++){
        p=(p*2)%mod;tmp=(tmp*(p-3))%mod;
        ans=(ans+4*tmp)%mod;
    }
    ans=(10+8*ans%mod+2*ans*ans%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}