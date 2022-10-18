#include<bits/stdc++.h>

#define myfor(i) for(int a##i=0;a##i<5;a##i++)
using namespace std;

int g[5][5];

int ans(int a1,int a2,int a3,int a4,int a5)
{
    int a[6]={0,a1,a2,a3,a4,a5};
    for(int i=1;i<=5;i++)
        for(int j=i+1;j<=5;j++)
            if(a[i]==a[j])
                return 0;
    int res=g[a1][a2]+g[a2][a1]+
            g[a3][a4]+g[a4][a3]+
            g[a2][a3]+g[a3][a2]+
            g[a4][a5]+g[a5][a4]+
            g[a3][a4]+g[a4][a3]+
            g[a4][a5]+g[a5][a4];
    /*printf("%d %d %d %d %d - %d\n",
           a1,a2,a3,a4,a5,res);
    if(res>32)
        scanf("%*c");*/
    return res;
}

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&g[i][j]);
    scanf("%*c");
    int m=0;
    myfor(1) myfor(2) myfor(3) myfor(4) myfor(5)
        m=max(m,ans(a1,a2,a3,a4,a5));
    printf("%d",m);
}