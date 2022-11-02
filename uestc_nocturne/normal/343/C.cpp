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
const LL oo=200000;
int n,m;
LL h[V],pos[V];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        cin>>h[i];
        for(int i=0;i<m;i++)
        cin>>pos[i];
        LL lo=-1,up=oo*oo;
        while(lo+1<up)
        {
            LL mid=(lo+up)/2;
            bool can=true;
            int p=0;
            for(int i=0;i<n;i++)
            {
                LL d=h[i]-pos[p],last=h[i]-1;
                if(d<=0)
                {
                    last=h[i]+mid;
                }
                else
                {
                    if(mid>=2*d)last=max(last,h[i]+mid-2*d);
                    if(mid>=d)last=max(last,h[i]+(mid-d)/2);
                }
                if(last<h[i])
                {
                    can=false;
                    break;
                }
                while(p!=m&&pos[p]<=last)p++;
                if(p==m)break;
            }
            if(p==m&&can)up=mid;
            else lo=mid;
        }
        cout<<up<<endl;
    }
}