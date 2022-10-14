#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int N=1000005;
    bool prime[N];
    for(int i=1;i<=N;i++)prime[i]=true;
    for(int i=2;i<=N;i++)
    {
        if(!prime[i])continue;
        for(int j=i+i;j<=N;j+=i)prime[j]=false;
    }
    int n;
    scanf("%i",&n);
    for(int i=1;i<=1000;i++)
    {
        if(!prime[n*i+1])
        {
            printf("%i",i);
            return 0;
        }
    }
    return 0;
}