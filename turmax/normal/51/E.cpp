#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx","avx2","fma","sse","sse2","sse3","sse4","sse4.2","tune=native")
#include <iostream>

using namespace std;
const int maxn=705;
int a[maxn][maxn];
int a2[maxn][maxn];
int a3[maxn][maxn];
int32_t main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;a[x][y]=1;a[y][x]=1;}
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(a[i][j]) for(int k=0;k<=i;++k) a2[i][k]+=a[j][k];
    for(int i=0;i<n;++i) for(int k=(i+1);k<n;++k) a2[i][k]=a2[k][i];
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(a[i][j]) for(int k=0;k<=i;++k) a3[i][k]+=a2[j][k];
    for(int i=0;i<n;++i) for(int k=(i+1);k<n;++k) a3[i][k]=a3[k][i];
    long long ans=0;
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) ans+=a2[i][j]*a3[j][i];
    for(int i=0;i<n;++i) ans-=5*a2[i][i]*a3[i][i];
    for(int i=0;i<n;++i) ans+=5*a3[i][i];
    cout<<ans/10;
    return 0;
}