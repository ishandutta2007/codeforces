#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ans[6]=
    {
        a+b+c,
        a+b*c,
        a*b+c,
        a*b*c,
        (a+b)*c,
        a*(b+c)
    };
    int m=0;
    for(int i=0;i<6;i++)
        m=max(m,ans[i]);
    printf("%d",m);
}