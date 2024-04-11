#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define int long long
const int N = 2e5+9;
int n,f[N][3][4];
char s[N];
int qpow(int x,int y){
    if(y<0) return 0;
    int t=1;
    while(y){
        if(y&1) (t*=x)%=mod;
        (x*=x)%=mod,y/=2;
    }
    return t;
}

signed main(){
    memset(f,0,sizeof(f));
    scanf("%lld%s",&n,s+1);int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(s[i]=='?');
    for(int i=1;i<=n;i++){
        for(int j=0;j<=3;j++){
            (f[i][0][j]+=f[i-1][0][j])%=mod,(f[i][1][j]+=f[i-1][1][j])%=mod,(f[i][2][j]+=f[i-1][2][j])%=mod;
            if(s[i]=='a'&&j==0) f[i][0][j]++;
            if(s[i]=='b') (f[i][1][j]+=f[i-1][0][j])%=mod;
            if(s[i]=='c') (f[i][2][j]+=f[i-1][1][j])%=mod;
            if(s[i]=='?'&&j!=3){
                (f[i][2][j+1]+=f[i-1][1][j])%=mod;
                if(j<=1) (f[i][1][j+1]+=f[i-1][0][j])%=mod;
                if(j==0) (f[i][0][j+1]+=1)%=mod;
            }
        }
    }
    int ans=f[n][2][0]*qpow(3,cnt)%mod+f[n][2][1]*qpow(3,cnt-1)%mod+f[n][2][2]*qpow(3,cnt-2)%mod+f[n][2][3]*qpow(3,cnt-3)%mod;
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}