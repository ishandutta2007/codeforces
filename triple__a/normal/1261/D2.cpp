#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
const int maxn=200007;

int n,k;
int f[maxn],rf[maxn];
int a[maxn];
int quick_power(int x,int y){
    int ans=1,t=x;
    while (y){
        if (y&1) ans=ans*t%mod;
        t=t*t%mod, y>>=1;
    }
    return ans;
}

int rev(int u){
    return quick_power(u,mod-2);
}

int mult(int u,int v){
    return u*v%mod;
}
int ans=0;
#undef int
int main(){
    cin>>n>>k;
    int val=0;
    if (k==1){
        printf("0");
        return 0;
    }
    for (int i=0;i<n;++i){
        cin>>a[i];
    }
    f[0]=1,rf[0]=1;
    for (int i=1;i<=n;++i){
        f[i]=f[i-1]*i%mod;
        rf[i]=rev(f[i]);
    }
    for (int i=1;i<=n;++i){
        if (a[i%n]!=a[i-1]) val++;
    }
    for (int i=0;i<=val/2;++i){
        ans=(ans+mult(mult(mult(f[val],rf[i]),mult(rf[i],rf[val-2*i])),quick_power(k-2,val-2*i)))%mod;
    }
    ans=mult((quick_power(k,val)-ans+mod)%mod,quick_power(k,n-val))*rf[2]%mod;
    cout<<ans<<endl;
    return 0;
}