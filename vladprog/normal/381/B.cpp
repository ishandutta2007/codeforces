#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int b[5001],m=0;
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        b[a]++;
        m=max(m,a);
    }
    for(int i=1;i<=5000;i++)
        b[i]=min(b[i],2);
    b[m]=1;
    int k=0;
    for(int i=1;i<=5000;i++)
        k+=b[i];
    printf("%d\n",k);
    for(int i=1;i<=5000;i++)
        if(b[i])
            printf("%d ",i),b[i]--;
    for(int i=5000;i>=1;i--)
        if(b[i])
            printf("%d ",i),b[i]--;
}