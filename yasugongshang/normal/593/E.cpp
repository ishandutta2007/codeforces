#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 25
#define mo 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

struct mat{
    int a[maxn][maxn];
}now;

bool bz[maxn][maxn];

int n,m,q,last;

const int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int poi(int x,int y){
    return (x-1)*m+y;
}

mat mul(mat x,mat y){
    mat z;
    mem(z.a,0);
    fo(i,1,n*m)
        fo(j,1,n*m)
            fo(k,1,n*m)
                z.a[i][j]=(z.a[i][j]+x.a[i][k]*1ll*y.a[k][j]) % mo;
    return z;
}

mat pow(mat x,int y){
    mat ret;
    mem(ret.a,0);
    fo(i,1,n*m) ret.a[i][i]=1;
    while (y) {
        if (y % 2 ==1) ret=mul(ret,x);
        x=mul(x,x);
        y /= 2;
    }
    return ret;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    last=1;
    fo(i,1,n*m) now.a[i][i]=1;
    fo(i,1,q) {
        int tp,x,y,t;
        scanf("%d%d%d%d",&tp,&x,&y,&t);
        mat tmp;
        mem(tmp.a,0);
        fo(j,1,n)
            fo(k,1,m) {
                fo(p,0,3) {
                    int xx=j+fx[p][0],yy=k+fx[p][1];
                    if (xx<=0 || yy<=0 || xx>n || yy>m) continue;
                    if (bz[j][k] || bz[xx][yy]) tmp.a[poi(j,k)][poi(xx,yy)]=0;
                    else tmp.a[poi(j,k)][poi(xx,yy)]=1;
                }
                if (bz[j][k]) tmp.a[poi(j,k)][poi(j,k)]=0;
                else tmp.a[poi(j,k)][poi(j,k)]=1;
            }
        now=mul(now,pow(tmp,t-last));
        if (tp==2) {
            bz[x][y]=1;
        }
        else if (tp==3) {
            bz[x][y]=0;
        }
        else {
            printf("%d\n",now.a[1][poi(x,y)]);
        }
        last=t;
    }
    return 0;
}
//qnq