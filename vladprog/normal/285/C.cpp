#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    long long s=0;
    for(int i=0;i<n;i++)
        s+=abs(i+1-a[i]);
    printf("%I64d",s);
}