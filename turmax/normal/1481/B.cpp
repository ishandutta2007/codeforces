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
        int h[n];
        for(int i=0;i<n;++i) cin>>h[i];
        bool ans=false;
        int pos=0;
        if(k>=20000) ans=true;
        for(int i=0;i<min((int) 20000,k);++i)
        {
            int curr=0;
            while(true)
            {
            if(curr==(n-1))
            {
            if(i==(k-1))
            {
                ans=true;
            }
            break;
            }
            if(h[curr]<h[curr+1]) {if(i==(k-1)) {pos=curr;}h[curr]++;break;}
            else curr++;
            }
        }
        if(ans) cout<<(-1)<<endl;
        else cout<<pos+1<<endl;
    }
    return 0;
}