#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3009;
int n,m,a,b,h[N][N];
void init(){
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    int u,x,y,z;scanf("%lld%lld%lld%lld",&u,&x,&y,&z);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            h[i][j]=u,u=(u*x+y)%z;
}
int q[N],l,r,f[N][N];
signed main(){
    init();
    for(int i=1;i<=n;i++){
        l=1,r=0;
        for(int j=1;j<=m;j++){
            while(l<=r&&h[i][j]<=h[i][q[r]]) r--;
            q[++r]=j;
            while(l<=r&&j-q[l]+1>b) l++;
            f[i][j]=h[i][q[l]];
        }
    }
    for(int j=1;j<=m;j++){
        l=1,r=0;
        for(int i=1;i<=n;i++){
            while(l<=r&&f[i][j]<=f[q[r]][j]) r--;
            q[++r]=i;
            while(l<=r&&i-q[l]+1>a) l++;
            h[i][j]=f[q[l]][j];    
        }
    }
    int ans=0;
    for(int i=a;i<=n;i++)
        for(int j=b;j<=m;j++) ans+=h[i][j];
    printf("%lld\n",ans);
    return 0;
}