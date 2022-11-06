#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 31

int n, i, j, k, ok, vmax, x, y, ml, o, nr[maxn], lg[maxn];
char s[maxn][maxn*maxn*maxn][maxn];
char sp[maxn][maxn];
int score[maxn][maxn*maxn*maxn], d[maxn][maxn*maxn*maxn], a[maxn][maxn*maxn*maxn], b[maxn][maxn*maxn*maxn];
vector<int> v[maxn][maxn*maxn*maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%s", sp[i]+1);
        lg[i]=strlen(sp[i]+1);
        ml=max(ml, lg[i]);
        for(int ps=1; ps<=lg[i]; ++ps)
            for(int j=1; j<=lg[i]-ps+1; ++j)
            {
                ok=1;
                for(int k=1; k<=nr[j]; ++k)
                {
                    o=1;
                    for(int l=1; l<=j; ++l)
                        if(s[j][k][l]!=sp[i][ps-1+l])
                        {
                            o=0;
                            break;
                        }
                    if(o==1)
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    nr[j]++;
                    vmax=0;
                    for(int k=1; k<=j; ++k)
                    {
                        s[j][nr[j]][k]=sp[i][ps-1+k];
                        score[j][nr[j]]+=sp[i][ps-1+k]-'a'+1;
                        vmax=max(vmax, (int) sp[i][ps-1+k]-'a'+1);
                    }
                    score[j][nr[j]]*=vmax;
                }
            }
    }
    for(int i=1; i<=ml; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=nr[i]; ++k)
                for(int ps=1; ps+i-1<=lg[j]; ++ps)
                {
                    ok=1;
                    for(int l=1; l<=i; ++l)
                        if(sp[j][ps+l-1]!=s[i][k][l])
                        {
                            ok=0;
                            break;
                        }
                    if(ok)
                    {
                        score[i][k]++;
                        break;
                    }
                }
    nr[0]=1;
    for(int i=0; i<ml; ++i)
        for(int j=1; j<=nr[i]; ++j)
            for(int k=1; k<=nr[i+1]; ++k)
            {
                ok=1;
                for(int l=1; l<=i; ++l)
                    if(s[i][j][l]!=s[i+1][k][l])
                    {
                        ok=0;
                        break;
                    }
                if(ok)
                {
                    v[i][j].push_back(k);
                    continue;
                }
                ok=1;
                for(int l=1; l<=i; ++l)
                    if(s[i][j][l]!=s[i+1][k][l+1])
                    {
                        ok=0;
                        break;
                    }
                if(ok)
                {
                    v[i][j].push_back(k);
                    continue;
                }
            }
    for(int i=ml; i>=0; --i)
        for(int j=1; j<=nr[i]; ++j)
        {
            d[i][j]=0;
            for(int k=0; k<v[i][j].size(); ++k)
            {
                if(d[i+1][v[i][j][k]]==0)
                {
                    d[i][j]=1;
                    break;
                }
            }
            x=y=0;
            if(i%2)
            {
                a[i][j]=score[i][j];
                y=2000000000;
                for(int k=0; k<v[i][j].size(); ++k)
                {
                    int fiu=v[i][j][k];
                    if(d[i+1][fiu]!=d[i][j])
                    {
                        if(x<b[i+1][fiu] || (x==b[i+1][fiu] && y>a[i+1][fiu]))
                        {
                            x=b[i+1][fiu];
                            y=a[i+1][fiu];
                        }
                    }
                }
                if(y!=2000000000)
                {
                    b[i][j]+=x;
                    a[i][j]+=y;
                }
            }
            else
            {
                b[i][j]=score[i][j];
                y=2000000000;
            //    printf("%d %d %d %d\n", i, j, a[i][j], b[i][j]);
                for(int k=0; k<v[i][j].size(); ++k)
                {
                    int fiu=v[i][j][k];
                    if(d[i+1][fiu]!=d[i][j])
                    {
                        if(x<a[i+1][fiu] || (x==a[i+1][fiu] && y>b[i+1][fiu]))
                        {
                       //     printf("*");
                            x=a[i+1][fiu];
                            y=b[i+1][fiu];
                        }
                    }
                }
              //  printf("%d %d %d %d\n", i, j, x, y);
                if(y!=2000000000)
                {
                    a[i][j]+=x;
                    b[i][j]+=y;
                }
            }
        }
    if(d[0][1]==1)
        printf("First\n", d[0][1]);
    else
        printf("Second\n");
    printf("%d %d\n", a[0][1], b[0][1]);
  /*  for(int i=1; i<=ml; ++i)
    {
        for(int j=1; j<=nr[i]; ++j)
        {
            printf("%d %d\n", a[i][j], b[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}