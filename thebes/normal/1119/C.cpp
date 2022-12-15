#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int a[MN][MN], b[MN][MN], n, m, i, j;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++) scanf("%d",&b[i][j]);
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(a[i][j]){
                a[i][j]=!a[i][j];
                a[i+1][j]=!a[i+1][j];
                a[i][j+1]=!a[i][j+1];
                a[i+1][j+1]=!a[i+1][j+1];
            }
            if(b[i][j]){
                b[i][j]=!b[i][j];
                b[i+1][j]=!b[i+1][j];
                b[i][j+1]=!b[i][j+1];
                b[i+1][j+1]=!b[i+1][j+1];
            }
        }
    }
    bool fnd = 1;
    for(i=1;i<=n;i++){
        if(a[i][m]!=b[i][m]) fnd = 0;
    }
    for(i=1;i<=m;i++){
        if(a[n][i]!=b[n][i]) fnd = 0;
    }
    printf("%s\n",fnd?"Yes":"No");
    return 0;
}