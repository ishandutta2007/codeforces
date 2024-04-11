#include<bits/stdc++.h>
using namespace std;
const int N = 4e3+9;
int n,m,a[N],b[N],c[N];
int p[N],o[N];
int f[N][N][2];

void prework(){
    for(int i=1;i<=n;i++) o[a[i]]++;
    for(int i=1;i<=n+m;i++){
        p[i]=max(p[i],o[i]);
        o[i+1]+=o[i]/2;
    }
    return ;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n+m;i++) scanf("%d",&c[i]);
    prework();
    memset(f,-0x3f,sizeof(f));
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=n+m;j>=1;j--) f[j][0][0]=max(f[j][0][0],0);
        for(int j=n+m;j>=1;j--){
            for(int k=0;k<=p[j];k++) f[j][k+1][1]=max(f[j][k+1][1],f[j][k][0]+c[j]);
            if(a[i]==j){
                for(int k=1;k<=p[j];k++){
                    f[j][k-1][1]=max(f[j][k-1][1],f[j][k][1]-b[i]);
                    f[j][k-1][0]=max(f[j][k-1][0],f[j][k][0]-b[i]);
                }
            }
            for(int k=0;k<=p[j];k++){
                // f[j][k]  f[j-1][k*2]
                f[j-1][k*2][0]=max(f[j-1][k*2][0],max(f[j][k][0],f[j][k][1])+k*2*c[j-1]);
            }
        }
    }
    ans=max(ans,max(f[1][0][0],f[1][0][1]));
    printf("%d\n",ans);
    return 0;
}