#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

#define MAXN 505
#define INF 1000000000
#define MAXA 29

int n,m,res,f[MAXN][MAXA][MAXA],g[MAXN][MAXA][MAXA];
char a[MAXN][MAXN],ix,iy;
struct{
    int x,y;
}pred[MAXN][MAXA][MAXA];

int main(){
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d\n",&n,&m);
    for (int i=0;i<n;i++)gets(a[i]);
    for (int i=0;i<n;i++)
        for (char x='a';x<='z';x++)
            for (char y='a';y<='z';y++){
                g[i][x-'a'][y-'a']=0;
                f[i][x-'a'][y-'a']=INF;
                for (int j=0;j<m;j++)
                    if (j%2)
                        g[i][x-'a'][y-'a']+=(y!=a[i][j]);
                    else g[i][x-'a'][y-'a']+=(x!=a[i][j]);
            }
    for (char x='a';x<='z';x++)
        for (char y='a';y<='z';y++)
            f[0][x-'a'][y-'a']=g[0][x-'a'][y-'a'];
    for (int i=1;i<n;i++)
        for (char x1='a';x1<='z';x1++)
            for (char y1='a';y1<='z';y1++)
                if (x1!=y1)
                    for (char x2='a';x2<='z';x2++)
                        for (char y2='a';y2<='z';y2++)
                            if (x2!=y2&&x2!=x1&&y2!=y1){
                                int prf=f[i][x2-'a'][y2-'a'];
                                f[i][x2-'a'][y2-'a']=std::min(f[i][x2-'a'][y2-'a'],f[i-1][x1-'a'][y1-'a']+g[i][x2-'a'][y2-'a']);
                                if (prf!=f[i][x2-'a'][y2-'a']){
                                    pred[i][x2-'a'][y2-'a'].x=x1;
                                    pred[i][x2-'a'][y2-'a'].y=y1;
                                }
                            }
    res=INF;
    for (char x='a';x<='z';x++)
        for (char y='a';y<='z';y++)
            if (x!=y&&f[n-1][x-'a'][y-'a']<res){
                res=f[n-1][x-'a'][y-'a'];
                ix=x;
                iy=y;
            }
    printf("%d\n",res);
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<m;j++)
            if (j%2)
                a[i][j]=iy;
            else a[i][j]=ix;
        char nx=pred[i][ix-'a'][iy-'a'].x,
             ny=pred[i][ix-'a'][iy-'a'].y;
        ix=nx;iy=ny;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            putchar(a[i][j]);
                printf("\n");
    }
}