#include <bits/stdc++.h>

using namespace std;

const int inf=1e9+10;
int n,m,mod;
int f[52][102],g[102];
int main(){
        int t1;
        cin>>n>>m>>mod>>t1;
        for(int i=0;i<=m;i++) fill(f[i],f[i]+mod,-inf);
        f[0][t1%mod]=0;
        for(int i=1;i<=n-1;i++){
                int val;
                cin>>val;
                val%=mod;
                for(int use=m-1;use>=0;use--){
                        for(int rem=0;rem<mod;rem++) {
                                //if (f[use][rem]!=-inf)cout<<i<<" "<<use<<" "<<rem<<" "<<f[use][rem]<<'\n';
                                g[(rem+val)%mod]=f[use][rem];
                                f[use+1][val]=max(f[use+1][val],f[use][rem]+rem);
                        }
                        for(int rem=0;rem<mod;rem++)
                                f[use][rem]=g[rem];
                        
                }
        }
        int ans=0;
        for(int rem=0;rem<mod;rem++) ans=max(ans,f[m-1][rem]+rem);
        cout<<ans;
}