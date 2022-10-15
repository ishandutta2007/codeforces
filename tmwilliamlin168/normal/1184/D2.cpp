#include<bits/stdc++.h>
using namespace std;
const int M=260;
typedef int ll;
typedef array<ll,M-1> vt;
 
const ll mod=1e9+7;
vt f[M][M+1];//coeff,0=constant term
vt eq[M-1];
ll v[M-1];
vt sl[M][M+1],sr[M][M+1];
int n,k,m;
ll inv[M+1];
vt mul(vt x,ll y){
    for(int i=0; i<m-1 ;i++) x[i]=x[i]*1LL*y%mod;
    return x;
}
vt add(vt x,vt y){
    for(int i=0; i<m-1 ;i++){
        x[i]+=y[i];
        if(x[i]>=mod) x[i]-=mod;
    }
    return x;
}
void sub(vt &x,vt y){
    for(int i=0; i<m-1 ;i++){
        x[i]-=y[i];
        if(x[i]<0) x[i]+=mod;
    }
}
ll pw(ll x,ll y){
    if(y==0) return 1;
    if(y%2) return pw(x,y-1)*1LL*x%mod;
    ll res=pw(x,y/2);
    return res*1LL*res%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    if(n<=2){
        cout << n << '\n';
        return 0;
    }
    for(int i=1; i<=m ;i++) inv[i]=pw(i,mod-2);
    for(int i=0; i<m ;i++) f[i][1][0]=i+1;
    for(int i=2; i<=m ;i++) f[0][i][0]=i;
    for(int i=1; i<=m-2 ;i++) f[i][2][i]=1;
   
    for(int j=1; j<=m ;j++){//compute f(i,j)
        for(int i=0; i+j<=m ;i++){
            if(j>=3 && i>=1){
                int cn=i+j-1,ck=j-1;
                f[i][j]=f[i][j-1];
                sub(f[i][j],mul(f[i+1][j-1],(cn-ck+1)*1LL*inv[cn+1]%mod*1LL*(m-cn)%mod*1LL*inv[m]%mod));
                sub(f[i][j],mul(mul(sl[i-1][j-1],inv[i]),(cn-ck)*1LL*inv[cn-1]%mod*1LL*cn%mod*1LL*inv[m]%mod));
                sub(f[i][j],mul(mul(sr[i][j-2],inv[j-2]),(ck-1)*1LL*inv[cn-1]%mod*1LL*cn%mod*1LL*inv[m]%mod));
                f[i][j]=mul(f[i][j],(cn+1)*1LL*inv[ck]%mod*1LL*m%mod*1LL*inv[m-cn]%mod);  
            }
            if(i==0) sl[i][j]=f[i][j];
            else sl[i][j]=add(sl[i-1][j],f[i][j]);
            sr[i][j]=add(sr[i][j-1],f[i][j]);
        }
    }
    for(int i=1; i<=m-2 ;i++){
        int cn=m,ck=m-i;
        eq[i]=f[i][m-i];
        sub(eq[i],mul(mul(sr[i][m-i-1],inv[m-i-1]),(ck-1)*1LL*inv[cn-1]%mod));
        sub(eq[i],mul(mul(sl[i-1][m-i],inv[i]),(cn-ck)*1LL*inv[cn-1]%mod));
    }
    for(int i=1; i<=m-2 ;i++){
        for(int j=i+1; j<=m-2 ;j++){
            sub(eq[j],mul(eq[i],eq[j][i]*1LL*pw(eq[i][i],mod-2)%mod));
        }
    }
    for(int i=m-2; i>=1 ;i--){
        ll cur=(mod-eq[i][0])%mod;
        for(int j=i+1; j<=m-2 ;j++){
            cur-=v[j]*1LL*eq[i][j]%mod;
            cur=(cur%mod+mod)%mod;
        }
        v[i]=cur*1LL*pw(eq[i][i],mod-2)%mod;
    }
    //cout << v[1] << ' ' << v[2] << ' ' << v[3] << endl;
    ll ans=f[n-k][k][0];
    for(int i=1; i<=m-2 ;i++){
        ans=(ans+f[n-k][k][i]*1LL*v[i])%mod;
    }
    cout << ans << '\n';
}