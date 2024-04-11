#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    while (n--)
    {
        char z[1000];
        scanf("%s",z);
        if (z[0]=='T') ans+=4;
        if(z[0]=='C') ans+=6;
        if(z[0]=='O')ans+=8;
        if(z[0]=='D') ans+=12;
        if(z[0]=='I') ans+=20;
    }
    printf("%d\n",ans);
}