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
const int V=1020;
int a[V][V];
int sqr(int x){return x*x;}
int n,m,i,j,ax,ay;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
        ax=-1;ay=-1;
        LL base=0,sx=0,sy=0,as=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            base+=(LL)a[i][j]*(sqr(2*i+1)+sqr(2*j+1));
            sx-=4*(2*i+1)*a[i][j];sy-=4*(2*j+1)*a[i][j];
            as+=4*a[i][j];
        }
        LL mi;
        for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
        {
            LL now=base;
            now+=as*(sqr(i)+sqr(j));
            now+=i*sx;now+=j*sy;
            if(ax==-1||now<mi)
            {mi=now,ax=i,ay=j;}
        }
        cout<<mi*4<<endl;
        cout<<ax<<" "<<ay<<endl;
    }
}