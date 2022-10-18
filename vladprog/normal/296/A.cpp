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
    int k=(n+3)/2;
    for(int i=0;i<n-k+1;i++)
        if(a[i]==a[i+k-1])
            return printf("NO"),0;
    printf("YES");
}