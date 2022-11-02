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
const int V=200100;
int r[V],a[V],n,ct[2][V];
bool cmp(int x,int y)
{return a[x]<a[y];}
void lisan()
{
    for(int i=0;i<2*n;i++)r[i]=i;
    sort(r,r+2*n,cmp);
    int M=1,pre=a[r[0]];
    a[r[0]]=1;
    for(int i=1;i<2*n;i++)
    {
        if(a[r[i]]!=pre)
        {pre=a[r[i]];M++;}
        a[r[i]]=M;
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&a[i+n]);
        }
        lisan();
        memset(ct,0,sizeof(ct));
        for(int i=0;i<n;i++)
        {
            ct[0][a[i]]++;
            if(a[i]!=a[i+n])
            ct[1][a[i+n]]++;
        }
        int ret=V;
        int hf=(n+1)/2;
        for(int i=1;i<V-10;i++)
        {
            if(ct[0][i]+ct[1][i]<hf)continue;
            ret=min(ret,max(0,hf-ct[0][i]));
        }
        if(ret==V)ret=-1;
        cout<<ret<<endl;
    }
}