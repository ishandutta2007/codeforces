#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 409;
const int mod = 1e9+7;
int n,a[N],b[N];
ll fac[N],C[N][N],siz[N],f[N][N];
void calc(){
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=(ll)i*fac[i-1]%mod;
}
int main(){
    scanf("%d",&n);
    calc();
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&a[i]);x=a[i];a[i]=1;
        for(int j=2;j*j<=x;j++)
            if(x%j==0){
                int y=0;
                while(x%j==0){x/=j,y++;}
                y%=2;if(y) a[i]*=j;
            }
        if(x!=1) a[i]*=x;
        b[i]=a[i];
    }
    memset(siz,0,sizeof(siz));
    sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-b-1;
    for (int i = 1; i <= n; i++){
        a[i]=lower_bound(b+1,b+len+1,a[i])-b;
        siz[a[i]]++;
    }
    memset(f,0,sizeof(f));int tot=0;
    f[0][0]=1;
    for(int i=0;i<len;i++){
        for(int j=0;j<=tot;j++){
            for(int k=1;k<=siz[i+1]&&k<=tot+1;k++){
                for(int D=0;D<=min(k,j);D++){
                    f[i+1][j-D+siz[i+1]-k]=(f[i+1][j-D+siz[i+1]-k]+f[i][j]*C[siz[i+1]-1][k-1]%mod*C[j][D]%mod*C[tot+1-j][k-D]%mod)%mod;
                }
            }
        }
        tot+=siz[i+1];
    }
    for(int i=1;i<=len;i++)
        f[len][0]=(f[len][0]*fac[siz[i]])%mod;
    printf("%lld\n",f[len][0]);
    return 0;
}