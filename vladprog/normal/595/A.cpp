#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int k=0;
    for(int i=1;i<=n*m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        k+=a|b;
    }
    printf("%d\n",k);
}