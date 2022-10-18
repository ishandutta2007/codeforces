#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    int l=0,m=0,r=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t<x)
            l++;
        else if(t==x)
            m++;
        else
            r++;
    }
    while((l+m+r+1)/2>l+m)
        m++;
    while(l+m+r+1-(l+m+r+1)/2>r+m)
        m++;
    cout<<l+m+r-n;
}