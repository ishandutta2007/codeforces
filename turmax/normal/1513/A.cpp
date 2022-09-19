#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if((2*k+1)>n) {cout<<(-1)<<endl;continue;}
        int ans[n];
        for(auto &h:ans) h=(-1);
        int curr=n;
        for(int i=1;i<(n-1);i+=2)
        {
            if(curr==(n-k)) break;
            ans[i]=curr;
            curr--;
            if(curr==(n-k)) break;
        }
        curr=1;
        for(int i=0;i<n;++i)
        {
            if(ans[i]==(-1))
            {
                ans[i]=curr;
                ++curr;
            }
        }
        for(auto h:ans) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}