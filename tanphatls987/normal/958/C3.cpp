#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

const int inf=1e9+10;
const int N=1e2+2,M=5e5+2;

int n,k,mod;
int a[M],psum[M];
int pos[M][N];
int f[N][N][N];
bool minimize(int &x,int y){
        if (x>y) x=y;else return 0;
        return 1;
}
int solve(){
        for(int i=0;i<N;i++)
                for(int j=0;j<N;j++) fill(f[i][j],f[i][j]+N,n+1);
        f[0][0][0]=0;
        for(int seg=0;seg<k;seg++){
                for(int rot=0;rot<=seg;rot++)
                        for(int tail=0;tail<mod;tail++){
                                int cur=f[seg][rot][tail];
                                
                                if (cur>n) continue;
                                for(int i=0;i<mod;i++){
                                        int ncur=pos[cur+1][i];
                                        int nrot=rot+(i<tail);
                                        minimize(f[seg+1][nrot][i],ncur);
                                }
                        }
        }
        int ans=inf;
        for(int rot=0;rot<=k;rot++)
                for(int tail=0;tail<mod;tail++){
                        int cur=f[k-1][rot][tail];
                        if (cur>=n) continue;
                        ans=min(ans,rot*mod+tail+(psum[n]-tail+mod)%mod);
                }
        return ans;
}
int main(){
        cin>>n>>k>>mod;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) psum[i]=(psum[i-1]+a[i])%mod;
        for(int j=0;j<mod;j++) pos[n+1][j]=n+1;
        for(int i=n;i>=1;i--){
                for(int j=0;j<mod;j++) pos[i][j]=pos[i+1][j];
                pos[i][psum[i]]=i;
        }
        cout<<solve();
}