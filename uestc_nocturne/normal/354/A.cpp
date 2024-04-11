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
const int oo=2000000000;
int L,R,ql,qr,n,w[V],s[V];
int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%d%d%d%d",&L,&R,&ql,&qr);
        for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
        s[0]=0;
        for(int i=1;i<=n;i++)s[i]=s[i-1]+w[i];
        int ret=oo;
        for(int i=0;i<=n;i++)
        {
            int tmp=s[i]*L+(s[n]-s[i])*R;
            if(i>n-i)tmp+=ql*(i-n+i-1);
            else if(n-i>i)tmp+=qr*(n-i-i-1);
            ret=min(ret,tmp);
        }
        cout<<ret<<endl;
    }
    return 0;
}