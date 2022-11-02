/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=60;
char map[V][V];
int set[V*V],nu[V*V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    if(find(x)==find(y))return;
    int p=find(x);set[p]=y;
}
int i,j,k,ii,jj,n,m,ans,t,tx,ty;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        ans=10000;t=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(map[i][j]=='.')continue;
            t++;
            int ct=0;
            for(k=0;k<4;k++)
            {
                tx=i+dx[k];
                ty=j+dy[k];
                if(tx<0||tx>=n)continue;
                if(ty<0||ty>=m)continue;
                if(map[tx][ty]=='#')ct++;
            }
            ans=min(ans,ct);
            for(k=0;k<n*m;k++)set[k]=k,nu[k]=0;
            for(ii=0;ii<n;ii++)
            for(jj=0;jj<m;jj++)
            {
                if(map[ii][jj]=='.')continue;
                if(ii==i&&jj==j)continue;
                for(k=0;k<4;k++)
                {
                    tx=ii+dx[k];
                    ty=jj+dy[k];
                    if(tx<0||tx>=n)continue;
                    if(ty<0||ty>=m)continue;
                    if(tx==i&&ty==j)continue;
                    if(map[tx][ty]=='#')
                    {
                        U(ii*m+jj,tx*m+ty);
                    }
                }               
            }
            ct=0;
            for(k=0;k<n*m;k++)if(map[k/m][k%m]=='#'&&k!=i*m+j)nu[find(k)]++;
            for(k=0;k<n*m;k++)if(nu[k])ct++;
            if(ct>1)ans=1;
        }
        if(t<=2)ans=-1;
        cout<<ans<<endl;
    }
}