#include<bits/stdc++.h>
using namespace std;

const int maxn=1007;
int n;
int a[maxn],p[maxn];
bool vis[maxn][maxn];
bool cmp(int u,int v){
    return a[u]>a[v];
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        p[i]=i;
    }
    sort(p,p+n,cmp);
    for (int i=0;i<n;++i){
        for (int j=0;j<a[p[i]];++j){
            vis[(i+j)%(n+1)][p[i]]=1;
        }
    }
    printf("%d\n",n+1);
    for (int i=0;i<=n;++i){
        for (int j=0;j<n;++j){
            printf("%d",vis[i][j]);
        }
        printf("\n");
    }
    return 0;
}