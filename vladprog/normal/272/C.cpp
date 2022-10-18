#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long a[n];
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    int m;
    scanf("%d",&m);
    long long k=0;
    for(int i=0;i<m;i++)
    {
        int w,h;
        scanf("%d%d",&w,&h);
        printf("%I64d\n",k=max(k,a[w-1]));
        k+=h;
    }
}