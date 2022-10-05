#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[105],d[105],end[105],n,i,j,sign=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>d[i];
        end[i]=a[i]+d[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j&&a[i]==end[j]&&a[j]==end[i])
            {
                sign=1;
            }
        }
    }
    if(sign){cout<<"YES";}
    else{cout<<"NO";}
}