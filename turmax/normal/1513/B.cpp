#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
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
        int curr=(1<<30)-1;
        for(auto h:a) curr=(curr & h);
        int sum=0;
        for(auto l:a)
        {
            if(l==curr)
            {
                ++sum;
            }
        }
        int ans=((sum*(sum-1))/2);
        ans%=p;
        for(int i=1;i<=(n-2);++i) {ans*=i;ans%=p;}
        ans%=p;
        cout<<(ans*2)%p<<'\n';
    }
    return 0;
}