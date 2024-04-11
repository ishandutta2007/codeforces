#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char c[n+1];
    scanf("%s",c);
    int p;
    scanf("%d",&p);
    int m=2e9;
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(c[i-1]=='R'&&c[i]=='L')
            m=min(m,x-p);
        p=x;
    }
    if(m==2e9)
        printf("-1");
    else
        printf("%d",m/2);
}