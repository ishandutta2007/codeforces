#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=4;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int x=min(a,b),y=min(c,d);
        if(x+y<=n)
            printf("%d %d %d\n",i,x,n-x),exit(0);
    }
    printf("-1\n");
}