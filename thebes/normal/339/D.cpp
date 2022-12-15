#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int st[MN][20], n, m, i, j, x, y;

int main(){
    for(scanf("%d%d",&n,&m),i=0;i<(1<<n);i++)
        scanf("%d",&st[i][0]);
    for(j=1;j<=n;j++){
        for(i=0;i<(1<<(n-j));i++){
            if(j%2) st[i][j]=st[2*i][j-1]|st[2*i+1][j-1];
            else st[i][j]=st[2*i][j-1]^st[2*i+1][j-1];
        }
    }
    for(;m;m--){
        scanf("%d%d",&x,&y); x--;
        st[x][0]=y;
        for(j=1;j<=n;j++)
            x>>=1, st[x][j]=(j%2)?st[2*x][j-1]|st[2*x+1][j-1]:st[2*x][j-1]^st[2*x+1][j-1];
        printf("%d\n",st[0][n]);
    }
    return 0;
}