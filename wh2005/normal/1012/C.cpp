#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+9;
int n,a[N];
int f[N][N][3];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,0x3f,sizeof(f));
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            //f[i-1][j][0]
            f[i][j][0]=min(f[i][j][0],f[i-1][j][0]);
            f[i][j+1][1]=min(f[i][j+1][1],f[i-1][j][0]+max(a[i-1]-a[i]+1,0));
            //f[i-1][j][1]
            f[i][j][2]=min(f[i][j][2],f[i-1][j][1]+max(a[i]-a[i-1]+1,0));
            //f[i-1][j][2]
            f[i][j+1][1]=min(f[i][j+1][1],f[i-1][j][2]+max(min(a[i-2]-1,a[i-1])-a[i]+1,0));
            f[i][j][0]=min(f[i][j][0],f[i-1][j][2]);
        }
    }
    for(int i=1;i<=(n+1)/2;i++) printf("%d ",min(f[n][i][0],min(f[n][i][1],f[n][i][2])));puts("");
    return 0;
}
/*
f[i][j][0/1/2]  i  j  i 
/i-1 



*/