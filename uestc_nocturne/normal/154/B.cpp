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
const int V=100100;
int is[V+10],p[V+10],pt;
void init()
{
    int i,j;
    memset(is,0,sizeof(is));pt=0;
    for(i=2;i<V;i++)
    {
        if(is[i])continue;
        p[pt++]=i;
        for(j=2;i*j<V;j++)
        is[i*j]=1;
    }
}
int id[V],on[V],i,n,m,x,ans;
char ch[120];
int main()
{
    init();
    while(~scanf("%d%d",&n,&m))
    {
        memset(id,-1,sizeof(id));
        memset(on,0,sizeof(on));
        while(m--)
        {
            scanf("%s%d",ch,&x);
            if(ch[0]=='+')
            {
                if(on[x])puts("Already on");
                else
                {
                    int te=x;
                    bool can=true;
                    for(int i=0;p[i]*p[i]<=x;i++)
                    {
                        if(te%p[i]==0)
                        {
                            if(id[p[i]]!=-1)
                            {can=false;ans=id[p[i]];break;}
                            while(te%p[i]==0)te/=p[i];
                        }
                    }
                    if(te!=1)
                    {
                        if(id[te]!=-1){ans=id[te];can=false;}
                    }
                    if(!can)printf("Conflict with %d\n",ans);
                    else
                    {
                        te=x;
                        for(int i=0;p[i]*p[i]<=x;i++)
                        {
                            if(te%p[i]==0)
                            {
                                id[p[i]]=x;
                                while(te%p[i]==0)te/=p[i];
                            }
                        }
                        if(te!=1)id[te]=x;
                        puts("Success");
                        on[x]=1;
                    }
                }
            }
            else
            {
                if(!on[x])puts("Already off");
                else
                {
                    int te=x;
                    for(int i=0;p[i]*p[i]<=x;i++)
                    {
                        if(te%p[i]==0)
                        {
                            id[p[i]]=-1;
                            while(te%p[i]==0)te/=p[i];
                        }
                    }
                    if(te!=1)id[te]=-1;
                    puts("Success");
                    on[x]=0;
                }
            }
        }
    }
}