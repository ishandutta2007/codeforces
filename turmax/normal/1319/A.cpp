#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int s1=0,s2=0;
    for(int i=0;i<n;++i)
    {
        if((a[i]-b[i])==1)
        {
            ++s1;
        }
        else if((a[i]-b[i])==(-1))
        {
            ++s2;
        }
    }
    if(s1==0)
    {
        cout<<(-1);
        return 0;
    }
    cout<<(s2+s1)/s1;
    return 0;
}