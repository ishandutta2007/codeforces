#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    cout<<a[n-1]-a[0]<<" ";
    if(a[0]==a[n-1])
    {
        cout<<(long long)n*(n-1)/2;
        return 0;
    }
    int x=0,y=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==a[0]) ++x;
        if(a[i]==a[n-1]) ++y;
    }
    cout<<(long long)x*y;
}