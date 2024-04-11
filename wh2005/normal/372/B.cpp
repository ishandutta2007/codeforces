#include<bits/stdc++.h>
using namespace std;
const int N = 49;
int n,m,q,a[N][N],f[N][N][N][N],sum[N][N][N][N],ans[N][N][N][N];
char s[N];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
    }
    memset(ans,0,sizeof(ans));
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int lst=1;
            for(int l=1;l<=i;l++){
                lst=(lst&&!a[i-l+1][j]);
                if(lst){
                    for(int r=1;r<=j;r++){
                        f[i][j][l][r]+=(1+f[i][j-1][l][r-1]);
                    }
                }
            }
            for(int r=1;r<=j;r++){
                int sum_f=0;
                for(int l=1;l<=i;l++){
                    sum_f+=f[i][j][l][r];
                    sum[i][j][l][r]+=sum[i-1][j][l-1][r];
                    sum[i][j][l][r]+=sum_f;
                }
            }
            for(int r=1;r<=j;r++){
                for(int l=1;l<=i;l++){
                    ans[i][j][l][r]+=ans[i][j-1][l][r-1];
                    ans[i][j][l][r]+=sum[i][j][l][r];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,c,d;scanf("%d%d%d%d",&x,&y,&c,&d);
        printf("%d\n",ans[c][d][c-x+1][d-y+1]);
    }    
    return 0;
}