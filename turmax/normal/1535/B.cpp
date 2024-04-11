#include <bits/stdc++.h>

using namespace std;
#define int long long
bool cmp(int x,int y)
{
    return (x%2)<(y%2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n,cmp);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=(i+1);j<n;++j)
            {
                if(__gcd(a[i],2*a[j])>1)
                {
                    ++ans;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}