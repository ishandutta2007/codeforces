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
const LL ooo=10010000;
const LL oo=ooo*ooo;
const int V=100100;
LL s[V];
int n;
int find(LL tmp)
{
    int lo=0,up=n+1,mid;
    while(lo+1<up)
    {
        mid=(lo+up)/2;
        if(s[mid]<=tmp)lo=mid;
        else up=mid;
    }
    return lo;
}
int tr[V];
void update(int k)
{
    while(k<=n)
    {
        tr[k]++;
        k+=k&-k;
    }
}
int read(int k)
{
    int ret=0;
    while(k)
    {
        ret+=tr[k];
        k-=k&-k;
    }
    return ret;
}
LL ts[V];
int pos[V];
LL Cal(LL tmp)
{
    LL ret=0;
    memset(tr,0,sizeof(tr));
    for(int i=1;i<=n;i++)
    {
        if(ts[i]-tmp>=0)ret++;
        int id=find(ts[i]-tmp);
        //if(tmp==5)printf("Cal : %d %d %d\n",i,id,read(id));
        ret+=read(id);
        update(pos[i]);
    }
    return ret;
}
struct Node
{
    LL va;
    int id;
}q[V];
bool cmp(Node x,Node y)
{return x.va<y.va;}
int i,x;
LL K;
int main()
{
    while(~scanf("%d",&n))
    {
        cin>>K;
        ts[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ts[i]=ts[i-1]+x;
            q[i].va=ts[i];
            q[i].id=i;
        }
        sort(q+1,q+n+1,cmp);
        for(i=1;i<=n;i++)pos[q[i].id]=i;
        for(i=1;i<=n;i++)s[i]=q[i].va;
        //for(i=1;i<=n;i++)cout<<s[i]<<" ";cout<<endl;
        LL lo=-oo,up=oo,mid;
        while(lo+1<up)
        {
            mid=(lo+up)/2;
            //cout<<mid<<" "<<Cal(mid)<<endl;
            if(Cal(mid)>=K)lo=mid;
            else up=mid;
        }
        cout<<lo<<endl;
    }
}