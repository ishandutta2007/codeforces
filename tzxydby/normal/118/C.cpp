#include<cstdio>
using namespace std;
int m,n,i,j,k,c,pd,a[10005],sum[10],ans[10][10005],d[10],f[10];
char s[10005];
int main()
{
    scanf("%d%d%s",&m,&n,&s);
    for(i=0;i<m;i++)
    {
        a[i]=s[i]-'0';
        sum[a[i]]++;
    }
    for(i=0;i<=9;i++)
    {
        pd=0;
        if(sum[i]>=n)
        {
            pd=1;
            d[i]=0;
            for(j=0;j<m;j++)
              ans[i][j]=a[j];
        }
        if(!pd)
        {
            for(j=0;j<m;j++)
              ans[i][j]=a[j];
            for(j=1;j<=9&&(d[i]+sum[i]<n);j++)
            {
                for(k=0;k<m&&(d[i]+sum[i]<n);k++)
                {
                    if(a[k]-i==j)
                    {
                        ans[i][k]=i;
                        d[i]++;
                        f[i]+=j;
                    }
                }
                for(k=m-1;k>=0&&(d[i]+sum[i]<n);k--)
                {
                    if(i-a[k]==j)
                    {
                        ans[i][k]=i;
                        d[i]++;
                        f[i]+=j ;
                    }
                }
            }
        }
    }
    c=f[0];
    j=0 ;
    for(i=1;i<10;i++)
    {
        if(f[i]<c)
        {
           c=f[i];
           j=i;
        }
        if(f[i]==c)
        {
            for(k=0,pd=0;k<m&&pd==0;k++)
            {
                if(ans[i][k]>ans[j][k])
                pd=1;
                else
                  if(ans[i][k]<ans[j][k])
                  {
                      pd=1 ;
                      j=i;
                  }
            }
        }
    }
    printf("%d\n",f[j]);
    for(i=0;i<m;i++)
    	printf("%d",ans[j][i]);
    printf("\n");
    return 0;
}