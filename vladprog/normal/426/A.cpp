#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int m=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        s-=a;
        m=max(m,a);
    }
    s+=m;
    printf((s>=0)?"YES":"NO");
}