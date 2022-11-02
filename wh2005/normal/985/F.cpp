#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200009;
const int mod1 = 1e9+7;
const int mod2 = 1e9+9;
int n,q;char s[N];ll hsh[N][30][2];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            hsh[i][j][0]=(hsh[i-1][j][0]<<1)%mod1+(s[i-1]==('a'+j-1));
            hsh[i][j][0]%=mod1;
            hsh[i][j][1]=(hsh[i-1][j][1]<<1)%mod2+(s[i-1]==('a'+j-1));
            hsh[i][j][1]%=mod2;
        }
    }
}
ll a[N],b[N];
ll qpow(ll x,ll y,ll mod){
    ll t=1;
    while(y){
        if(y&1) (t*=x)%=mod;
        (x*=x)%=mod,y/=2;
    }
    return t;
}
int main(){
    scanf("%d%d",&n,&q);scanf("%s",s);init();   
    for(int i=1;i<=q;i++){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);ll bas=qpow(2,z,mod1);
        for(int j=1;j<=26;j++){
            a[j]=(hsh[x+z-1][j][0]-hsh[x-1][j][0]*bas%mod1+mod1)%mod1;
            b[j]=(hsh[y+z-1][j][0]-hsh[y-1][j][0]*bas%mod1+mod1)%mod1;
        }
        sort(a+1,a+26+1);sort(b+1,b+26+1);
        int flag=1;
        for(int i=1;i<=26;i++) if(a[i]!=b[i]) flag=0;
        if(!flag){printf("NO\n");continue;}bas=qpow(2,z,mod2);
        for(int j=1;j<=26;j++){
            a[j]=(hsh[x+z-1][j][1]-hsh[x-1][j][1]*bas%mod2+mod2)%mod2;
            b[j]=(hsh[y+z-1][j][1]-hsh[y-1][j][1]*bas%mod2+mod2)%mod2;
        }
        sort(a+1,a+26+1);sort(b+1,b+26+1);
        for(int i=1;i<=26;i++) if(a[i]!=b[i]) flag=0;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }   
    return 0;
}