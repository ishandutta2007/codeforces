#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    sort(x,x+n);
    int ans=1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(x[j]-x[i]<=d)
                ans=max(ans,j-i+1);
    cout<<n-ans;
}