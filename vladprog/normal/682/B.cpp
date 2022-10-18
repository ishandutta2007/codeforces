#include<bits/stdc++.h>

using namespace std;

const long long z=0;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    a[0]=1;
    for(int i=1;i<n;i++)
        a[i]=min(a[i],a[i-1]+1);
    cout<<a[n-1]+1;
}