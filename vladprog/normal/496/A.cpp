#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int one=0;
    for(int i=1;i<n;i++)
        one=max(one,a[i]-a[i-1]);
    int two=1e3;
    for(int i=1;i<n-1;i++)
        two=min(two,a[i+1]-a[i-1]);
    printf("%d",max(one,two));
}