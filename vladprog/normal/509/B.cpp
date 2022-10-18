#include<bits/stdc++.h>

using namespace std;

const int inf=1000;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],l=inf,r=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    if(k<r-l)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<l;j++)
                cout<<"1 ";
            for(int j=l;j<a[i];j++)
                cout<<j-l+1<<" ";
            cout<<endl;
        }
    }
}