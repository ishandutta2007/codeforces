#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[2100];
    bool flag1=0,flag2=0;
    cin>>n;
    for(int i=0;i<n*2;i++)
    {
        scanf("%d",&a[i]);
        if(i&&a[i]!=a[i-1])flag1=1;
        if(i&&a[i]<a[i-1])flag2=1;
    }
    if(!flag1)cout<<"-1";
    else
    {
        sort(a,a+n*2);
        if(flag2)
        {
            for(int i=0;i<2*n;i++)
            {
                if(i)cout<<" ";
                cout<<a[i];
            }
        }
        else
        {
            for(int i=0;i<2*n;i++)
            {
                if(i)cout<<" ";
                cout<<a[n*2-i-1];
            }
        }
    }
    return 0;
}