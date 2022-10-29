#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7; 
int n,m,k,r,c,x1,y1,x2,y2; 
int fpw(int x,int k,int p) {
    int ret=1;
    while (k) {
        if (k&1) ret=1ll*ret*x%p; 
        x=1ll*x*x%p;k >>=1; 
    }
    return ret; 
}
int solve(int n,int m,int r,int c) {
 //   cout<<n<<' '<<m<<' '<<r<<' '<<c<<'\n'; 
    if (r<0 || c<0 || (r==n && c==m)) return fpw(k,1ll*n*m%(mod-1),mod);
    if (2*r<=n||2*c<=m) {
        int q=(1ll*n*m%(mod-1))-(1ll*r*c%(mod-1));
        q=(q%(mod-1)+mod-1)%(mod-1);
        return fpw(k,q,mod); 
    }
    int q=2ll*(n-r)%(mod-1)*(m-c)%(mod-1);
    return 1ll*solve(r,c,2*r-n,2*c-m)*fpw(k,q,mod)%mod; 
}
int main() {
    cin>>n>>m>>k>>r>>c;
    cin>>x1>>y1>>x2>>y2; 
    int N=max(x1+r-1,x2+r-1)-min(x1,x2)+1;
    int M=max(y1+c-1,y2+c-1)-min(y1,y2)+1; 
    int q=(1ll*n*m%(mod-1))-(1ll*N*M%(mod-1));
    q=(q%(mod-1)+mod-1)%(mod-1);
    int ans=fpw(k,q,mod);
    printf("%lld\n",1ll*ans*solve(N,M,r,c)%mod); 
    return 0;
}