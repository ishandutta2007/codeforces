#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
    if(x==0)return 0;
    if(x%2)return f(x/2)+1;
    return f(x/2);
}

int main()
{
    int n;
    scanf("%d",&n);
    long long k[40];
    memset(k,0,sizeof(k));
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        k[f(a)]++;
    }
    long long s=0;
    for(int i=0;i<40;i++)
        s+=k[i]*(k[i]-1)/2;
    printf("%I64d",s);
}