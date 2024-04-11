#include<bits/stdc++.h>
using namespace std;
const int N = 509;
int T,n,m,a[N][N],b[N][N];
int p[N*N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++) scanf("%d",&b[i][j]);
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++) p[a[i][j]]=i;
        for(int i=1;i<=n;i++){
            int x=p[b[1][i]];
            for(int j=1;j<=m;j++) printf("%d ",a[x][j]);
            puts("");
        }
    }
    return 0;
}