#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    scanf("%d",&n);
    int m=0,s=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        m=max(m,a);
        s+=a;
    }
    printf("%d",m*n-s);
}