#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++)
    {
        char c[2];
        scanf("%s",c);
        if(c[0]=='C'||c[0]=='M'||c[0]=='Y')
            printf("#Color"),exit(0);
    }
    printf("#Black&White");
}