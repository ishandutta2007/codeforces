#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ind=0,m=1e9;
    for(int i=0;i<k;i++)
    {
        int s=0;
        for(int j=i;j<n;j+=k)
            s+=a[j];
        if(m>s)
            m=s,ind=i;
    }
    printf("%d",ind+1);
}