#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 509;
int n;ll f[N][N];
struct pp{ll a,b,k;}p[N];
bool cmp(pp x,pp y){return x.b>y.b;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].k);
    sort(p+1,p+n+1,cmp);
    memset(f,-1,sizeof(f));f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(f[i-1][j]!=-1) f[i][j]=max(f[i-1][j],f[i][j]);
            if(f[i-1][j]!=-1) f[i][j]=max(f[i][j],f[i-1][j]+p[i].a-p[i].b*p[i].k);
            if(j&&f[i-1][j-1]!=-1) f[i][j]=max(f[i][j],f[i-1][j-1]+p[i].a-p[i].b*min((ll)(j-1),p[i].k));
        }
    }
    ll ans=0;
    for(int i=0;i<=n;i++) ans=max(ans,f[n][i]);
    printf("%lld\n",ans);
    return 0;
}