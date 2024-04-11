#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 3e3+9;
const ll mod = 1e9+7;
int n,m,a[N][N];
char s[N];
ll f[N][N];
ll calc(int u,int v,int x,int y){
    if(a[u][v]) return 0;
    memset(f,0,sizeof(f));
    f[u][v]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i==u&&j==v) continue;
            if(a[i][j]) continue;
            f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
        }
    return f[x][y];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=1;j<=m;j++){
            if(s[j-1]=='.') a[i][j]=0;
            if(s[j-1]=='#') a[i][j]=1;
        }
    }
    ll ans=calc(1,2,n-1,m)*calc(2,1,n,m-1)%mod-calc(1,2,n,m-1)*calc(2,1,n-1,m)%mod;
    ans=(ans%mod+mod)%mod;printf("%lld\n",ans);
    return 0;
}