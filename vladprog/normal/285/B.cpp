#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,s,t;
    scanf("%d%d%d",&n,&s,&t);
    int p[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int c=0;
    while(c<=n)
    {
        if(s==t)return printf("%d",c),0;
        s=p[s];
        c++;
    }
    printf("-1");
}