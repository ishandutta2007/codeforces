#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    int m;
    cin>>n>>m;
    vector <int> a(n);
    int k;
    vector <int> b(n-1);
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a[i]=k;
        if(i>=1)
        {
            b[i-1]=a[i]-a[i-1];
        }
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    int sum=0;
    sum+=a[n-1]-a[0];
    for(int i=0;i<(m-1);++i)
    {
        sum-=b[i];
    }
    cout<<sum;
    return 0;
}