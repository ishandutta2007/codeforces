#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e6+9;
const ll mod = 1e9+7;
int n,m,len,a[N];
ll S[N],A[N],pw[N];
void FWTand(ll *f,ll x){
    for(int p=2,k=1;p<=len;p<<=1,k<<=1)
        for(int i=0;i<len;i+=p)
            for(int j=0;j<k;j++)
                f[i+j]=((f[i+j]+x*f[i+j+k]%mod)%mod+mod)%mod;
    return ;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),m=max(m,a[i]);
    len=1;while(len<=m) len<<=1;
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=(pw[i-1]<<1)%mod;
    for(int i=1;i<=n;i++) A[a[i]]++;
    FWTand(A,1);    
    for(int i=0;i<len;i++) A[i]=pw[A[i]];
    FWTand(A,mod-1);
    if(pw[n]==A[0]) printf("%lld\n",A[0]-1);
    else printf("%lld\n",A[0]);
    return 0;
}