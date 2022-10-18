#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int b[m];
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    sort(b,b+m);
    int k=0;
    for(int i=0,j=0;i<n;i++)
    {
        while(j<m&&a[i]>b[j])
            j++;
        if(j<m)
            j++;
        else
            k++;
    }
    printf("%d",k);
}