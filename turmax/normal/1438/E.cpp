#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    set <pair<int,int> > z;
    for(int i=0;i<n;++i)
    {
        int c,l,sum;
        if(i<(n-1))
        {
        c=0;
        l=(i+1);
        sum=a[i+1];
        if((a[l+1]^a[i])==sum) z.insert({i,l+1});
        while(true)
        {
            ++l;
            sum+=a[l];
            if(l>=(n-1))
            {
                break;
            }
            if((2*a[l])>=a[i])
            {
                ++c;
            }
            if(c>=3) break;
            if((a[l+1]^a[i])==sum) z.insert({i,l+1});
        }
        }
        if(i>=1)
        {
        c=0;
        l=(i-1);
        sum=a[i-1];
        if((a[l-1]^a[i])==sum) z.insert({l-1,i});
        while(true)
        {
            --l;
            sum+=a[l];
            if(l<=0)
            {
                break;
            }
            if((2*a[l])>=a[i])
            {
                ++c;
            }
            if(c>=3) break;
            if((a[l-1]^a[i])==sum) z.insert({l-1,i});
        }
        }
    }
    //for(auto h:z) cout<<h.first<<' '<<h.second<<endl;
    cout<<z.size();
    return 0;
}