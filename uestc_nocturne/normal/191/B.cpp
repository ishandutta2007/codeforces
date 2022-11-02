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
struct Node{int va,id;}q[V];
bool cmp(Node x,Node y)
{return x.va>y.va;}
LL all;
int pos[V],n,K,i,ret;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        cin>>all;
        for(i=0;i<n;i++)
        {
            scanf("%d",&q[i].va);
            q[i].id=i;
        }
        ret=n;
        sort(q,q+n-1,cmp);
        for(i=0;i<n-1;i++)pos[q[i].id]=i;
        LL s1=0;
        for(i=0;i<K-1;i++)s1+=q[i].va;
        LL s2=s1+q[K-1].va;
        for(i=0;i<n-1;i++)
        {
            if(pos[i]>=K-1)
            {
                if(q[pos[i]].va+s1>all)
                ret=min(ret,i+1);
            }
            else
            {
                if(s2>all)
                ret=min(ret,i+1);
            }
        }
        cout<<ret<<endl;
    }
}