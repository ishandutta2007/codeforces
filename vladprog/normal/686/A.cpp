#include<bits/stdc++.h>

using namespace std;

int main()
{
    #define int long long
    int n,x;
    scanf("%I64d%I64d",&n,&x);
    int g=0;
    for(int i=0;i<n;i++)
    {
        char c;
        int d;
        scanf("%*c%c%I64d",&c,&d);
        if(c=='+')
            x+=d;
        else
            if(x>=d)
                x-=d;
            else
                g++;
    }
    printf("%I64d %I64d",x,g);
}