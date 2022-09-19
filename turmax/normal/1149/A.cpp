#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int sum=0;
    int c1=0;
    int c2=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]==1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    if(c2>=1)
    {
        cout<<2<<" ";
        sum-=2;
        c2--;
    }
    if(sum%2==1)
    {
        for(int i=0;i<c1;++i)
        {
            cout<<1<<" ";
        }
        for(int i=0;i<c2;++i)
        {
            cout<<2<<" ";
        }
        return 0;
    }
    else
    {
        for(int i=1;i<c1;++i)
        {
            cout<<1<<" ";
        }
        for(int i=0;i<c2;++i)
        {
            cout<<2<<" ";
        }
        if(c1>=1)
        cout<<1<<" ";
        return 0;
    }
    return 0;
}