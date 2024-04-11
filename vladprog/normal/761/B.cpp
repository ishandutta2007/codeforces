#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int b[n];
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
    {
        int d=-1;
        bool ok=true;
        for(int j=0;j<n;j++)
        {
            int t=(a[j]+l-b[(i+j)%n])%l;
            if(d==-1)
                d=t;
            if(d!=t)
                ok=false;
        }
        if(ok)
            printf("YES"),exit(0);
    }
    printf("NO");
}