#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const int MOD=1e9+7;

typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int alp=26;

ll f[N],fac[N];
ll rev[N],revfac[N];

ll C(int n,int k){
    if (k<0||k>n) return 0;
    return fac[n]*revfac[k]%MOD*revfac[n-k]%MOD;
}
int main(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%MOD;
    rev[1]=1;
    for(int i=2;i<N;i++) rev[i]=MOD-(MOD/i)*rev[MOD%i]%MOD;
    revfac[0]=1;
    for(int i=1;i<N;i++) revfac[i]=revfac[i-1]*rev[i]%MOD;
    int n,k;
    cin>>n>>k;
    f[0]=1;

    ll ans=0;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%MOD;
        if (i>=k+1){
            ll dis=f[i-k-1]*C(i-1,i-k-1)%MOD*fac[k]%MOD;
            f[i]=(f[i]-dis)%MOD;
            ans=(ans+dis*C(n-1,i)%MOD*fac[n-i])%MOD;
        }
    }
    cout<<(ans+MOD)%MOD;
}