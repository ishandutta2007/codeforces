//http://codeforces.ru/problemset/problem/111/C
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n,m;
int f[44][2111],st3[111];

int bit(int mask,int x){
    if (x<0||x>=m)return 0;
    return (mask/st3[x])%3;
}

int main()
{
    scanf("%d%d",&n,&m);
    if (n<m){
        int tmp=n;n=m;m=tmp;
    }
    st3[0]=1;
    for(int i=1;i<11;i++)
        st3[i]=st3[i-1]*3;
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for (int i=0;i<n;i++)
        for (int m1=0;m1<st3[m];m1++)
            if (f[i][m1]!=-1)
                for (int m2=0;m2<st3[m];m2++){
                    bool ok=true;
                    int cr=0;
                    for (int j=0;j<m;j++){
                        if (bit(m2,j)==0&&bit(m2,j-1)!=1&&bit(m2,j+1)!=1&&bit(m1,j)!=1){
                            ok=false;
                            break;
                        }
                        if (bit(m2,j)!=1&&bit(m1,j)==2){
                            ok=false;
                            break;
                        }
                        if (bit(m2,j)!=1)cr++;
                    }
                    if (!ok)continue;
                    f[i+1][m2]=max(f[i+1][m2],f[i][m1]+cr);
                }
    int res=0;
    for (int mask=0;mask<st3[m];mask++){
        bool ok=true;
        for (int i=0;i<m;i++)
            if (bit(mask,i)==2){
                ok=false;
                break;
            }
        if (!ok)continue;
        res=max(res,f[n][mask]);
    }
    printf("%d\n",res);
    return 0;
}