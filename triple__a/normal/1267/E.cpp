#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[107][107],p[107],d[107],ans=-1,idx=-1;
bool vis[107][107];
bool cmp(int u,int v){
    return d[u]<d[v];
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=n-1;++i){
        for (int j=1;j<=m;++j){
            d[j]=a[j][n]-a[j][i];
            p[j]=j;
        }
        sort(p+1,p+m+1,cmp);
        int sum=0,j;
        for (j=1;j<=m;++j){
            sum+=d[p[j]];
            if (sum>0) break;
            vis[i][p[j]]=1;
        }
        if (ans<j){
            ans=j,idx=i;
        }
    }
    printf("%d\n",m-ans+1);
    for (int i=1;i<=m;++i){
        if (!vis[idx][i]) printf("%d ",i);
    }
    return 0;
}