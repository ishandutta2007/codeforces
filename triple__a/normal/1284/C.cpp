#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=300007;

int n,m;
int mult(int u,int v){
    return 1ll*u*v%m;
}
int fac[maxn];
#undef int
int main(){
    scanf("%d%d",&n,&m);
    fac[0]=1;
    for (int i=1;i<=n;++i) fac[i]=mult(fac[i-1],i);
    int ans=0;
    for (int i=1;i<=n;++i){
        ans=(ans+mult(mult(n-i+1,n-i+1),mult(fac[i],fac[n-i])))%m;
    }
    printf("%d\n",ans);
}