#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 3e5+9;
int n;
ll a[3][N],p[3][N];

map<ll ,int >mp,f[N];

int dfs(int x,int y){
    if(x<0||y<0) return -1;
    if(x==0&&y==0) return 0;
    if(f[x].count(y)) return f[x][y];
    return f[x][y]=max(0,1+max((p[1][x]<p[2][y]?dfs(x,p[2][y]):dfs(p[1][x],y)),dfs(p[0][min(x,y)],p[0][min(x,y)])));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[1][i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[2][i]);
    for(int i=1;i<=n;i++) a[0][i]=a[1][i]+a[2][i];
    for(int i=1;i<=n;i++){
        a[0][i]+=a[0][i-1];
        a[1][i]+=a[1][i-1];
        a[2][i]+=a[2][i-1];
    }
    p[0][0]=-1,p[1][0]=-1,p[2][0]=-1;
    for(int i=0;i<=2;i++){
        mp.clear();mp[0]=1;
        for(int j=1;j<=n;j++){
            p[i][j]=mp[a[i][j]]-1;
            p[i][j]=max(p[i][j],p[i][j-1]);
            mp[a[i][j]]=j+1;
        }
    }
    printf("%d\n",dfs(n,n));
    return 0;
}