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
int a[V],b[V],n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        LL sa=0;
        for(int i=0;i<n;i++)sa+=a[i];
        LL sb=0;
        for(int i=0;i<m;i++)sb+=b[i];
        LL ret1=sa;
        for(int i=0;i+1<m;i++)ret1+=min(sa,(LL)b[i]);
        LL ret2=sb;
        for(int i=0;i+1<n;i++)ret2+=min(sb,(LL)a[i]);
        cout<<min(ret1,ret2)<<endl;;
    }
    return 0;
}