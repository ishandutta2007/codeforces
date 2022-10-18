#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int m=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        m=max(m,x);
        for(int j=i+1;j<n;j++)
            m=max(m,x=x^a[j]);
    }
    printf("%d\n",m);
}