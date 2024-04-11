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
const int V=500100;
struct Edge{int pos,ne;}e[V];
int K,hd[V];
void add(int x,int pos)
{
    e[K].pos=pos;
    e[K].ne=hd[x];hd[x]=K++;
}
struct tree
{
    tree *ne[26];
}tr[V],VD,*root;
int tn;
void init()
{
    tr[tn=0]=VD;
    root=tr+(tn++);
}
char s[120];
void build(int pos)
{
    tree *p=root;
    for(int i=0;s[i];i++)
    {
        if(p->ne[s[i]-'a']==NULL)
        {
            tr[tn]=VD;
            hd[tn]=-1;
            p->ne[s[i]-'a']=tr+(tn++);
        }
        p=p->ne[s[i]-'a'];
    }
    add(p-tr,pos);
}
char map[120][120];
int n,word[V];
void doit(int id)
{
    tree *p=root;
    for(int i=0;map[id][i];i++)
    {
        if(p->ne[map[id][i]-'a']==NULL)return;
        p=p->ne[map[id][i]-'a'];
    }
    for(int i=hd[p-tr];i!=-1;i=e[i].ne)
    word[e[i].pos]=id;
}
const int N=(1<<15)+10;
int last[V][16],ct[N][17],dp[N][200],Q,i,j,k,ii,jj,Mp,ss,m;
int main()
{
    for(i=0;i<26;i++)VD.ne[i]=NULL;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        int id=-1,mi;
        scanf("%d",&Q);
        Mp=n*(n-1)/2;
        for(i=0;i<(1<<n);i++)
        for(j=0;j<n;j++)
        {
            ct[i][j]=0;
            if(i&(1<<j))continue;
            for(k=j+1;k<n;k++)
            if(i&(1<<k))ct[i][j]++;
        }
        for(ss=1;ss<=Q;ss++)
        {
            scanf("%d",&m);
            init();
            for(i=0;i<m;i++)
            {
                scanf("%s",s);
                build(i);
            }
            for(i=0;i<=m;i++)word[i]=-1;
            for(i=0;i<n;i++)doit(i);
        //  for(i=0;i<m;i++)printf("%d ",word[i]);puts("");
            for(i=0;i<n;i++)last[m][i]=m+1;
            for(i=m-1;i>=0;i--)
            {
                for(j=0;j<n;j++)last[i][j]=last[i+1][j];
                if(word[i]!=-1)last[i][word[i]]=i;
            }
        //  for(i=0;i<n;i++,puts(""))for(j=0;j<m;j++)printf("%d ",last[j][i]);
            for(i=0;i<(1<<n);i++)
            for(j=0;j<=Mp;j++)
            dp[i][j]=m+1;
            dp[0][0]=0;
            for(i=0;i<(1<<n);i++)
            for(j=0;j<=Mp;j++)
            {
                if(dp[i][j]>=m)continue;
        //      printf("%d %d %d\n",i,j,dp[i][j]);
                for(k=0;k<n;k++)
                {
                    if(i&(1<<k))continue;
                    if(last[dp[i][j]][k]>=m)continue;
                    ii=i^(1<<k);jj=j+ct[i][k];
                    dp[ii][jj]=min(dp[ii][jj],last[dp[i][j]][k]+1);
                }
            }
            int mm=100100;
            for(i=0;i<=Mp;i++)
            if(dp[(1<<n)-1][i]<=m)
            {mm=i;break;}
            if(mm!=100100&&(id==-1||mi>mm))
            {id=ss;mi=mm;}
        }
        //printf("%d\n",mi);
        if(id==-1)puts("Brand new problem!");
        else
        {
            printf("%d\n",id);
            printf("[:");
            for(i=0;i<Mp-mi+1;i++)
            printf("|");
            puts(":]");
        }
    }
}