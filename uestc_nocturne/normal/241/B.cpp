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
const int V=51000*30;
struct Node
{
    Node *ne[2];
    int s[30],ct;
}tr[V],*Root,VD;
int tn;
const int P=1000000007;
int po[40];
void init()
{
    po[0]=1;
    for(int i=1;i<33;i++)po[i]=po[i-1]*2;
    for(int i=0;i<30;i++)VD.s[i]=0;
    VD.ne[0]=VD.ne[1]=NULL;VD.ct=0;
    tr[tn=0]=VD;
    Root=tr+(tn++);
}
int n,id[40];
void add(int x)
{
    Node *p=Root;
    for(int i=29;i>=0;i--)
    {
        if(x&(1<<i))id[i]=1;
        else id[i]=0;
    }
    for(int i=29;i>=0;i--)
    {
        if(p->ne[id[i]]==NULL)
        {
            tr[tn]=VD;
            p->ne[id[i]]=tr+(tn++);
        }
        p=p->ne[id[i]];
        p->ct++;
        for(int j=0;j<30;j++)
        if(id[j]==0)p->s[j]++;
    }
}
int rt[40];
int find(int va,int x)
{
    int ret=0;
    Node *p=Root;
    for(int i=29;i>=0;i--)
    {
        if(x&(1<<i))id[i]=1;
        else id[i]=0;
        if(va&(1<<i))rt[i]=1;
        else rt[i]=0;
    }
    for(int i=29;i>=0;i--)
    {
        if(rt[i]==0)
        {
            if(p->ne[id[i]^1]!=NULL)
            ret+=p->ne[id[i]^1]->ct;
        }
        if(p->ne[id[i]^rt[i]]==NULL)return ret;
        p=p->ne[id[i]^rt[i]];
    }
    ret+=p->ct;
    return ret;
}
int get(int va,int x)
{
    if(va==po[30])return 0;
    int ret=0;
    Node *p=Root;
    for(int i=29;i>=0;i--)
    {
        if(x&(1<<i))id[i]=1;
        else id[i]=0;
        if(va&(1<<i))rt[i]=1;
        else rt[i]=0;
    }
    for(int i=29;i>=0;i--)
    {
        if(rt[i]==0)
        {
            if(p->ne[id[i]^1]!=NULL)
            for(int j=0;j<30;j++)
            {
                int tp=p->ne[id[i]^1]->s[j];
                if(id[j]==0)tp=p->ne[id[i]^1]->ct-tp;
                ret+=(LL)tp*po[j]%P;
                ret%=P;
            }
        }
        if(p->ne[id[i]^rt[i]]==NULL)return ret;
        p=p->ne[id[i]^rt[i]];
    }
    for(int j=0;j<30;j++)
    {
        int tp=p->s[j];
        if(id[j]==0)tp=p->ct-tp;
        ret+=(LL)tp*po[j]%P;ret%=P;
    }
    return ret;
}
int a[V];
LL K;
LL Cal(int mid)
{
    if(mid==po[30])return 0;
    LL ret=0;
    for(int i=0;i<n;i++)
    ret+=find(mid,a[i]);
    return ret;
}
int main()
{
    while(~scanf("%d%I64d",&n,&K))
    {
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            add(a[i]);
        }
        int lo=-1,up=po[30];
        while(lo+1<up)
        {
            int mid=lo/2+up/2;
            if(lo%2&&up%2)mid++;
            if(Cal(mid)/2>=K)lo=mid;
            else up=mid;
        }
        LL nd=2*K-Cal(lo+1);
        int ret=nd*lo%P;
        for(int i=0;i<n;i++)
        ret=(ret+get(lo+1,a[i]))%P;
        if(ret%2==0)ret/=2;
        else ret=(ret+P)/2;
        printf("%d\n",ret);
    }
}