#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int a[1010];
long long sum;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=(long long)i*(a[i]-1);
    }
    sum+=n;
    printf("%I64d",sum);
    return 0;
}