#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> go2(vector <int> v)
{
    vector <int> z;
    z.push_back(1e18);
    z.push_back(1e18);
    for(int i=v.size()-1;i>=0;i--)
    {
        z.push_back(min(z.back(),v[i]));
    }
    reverse(z.begin(),z.end());
    return z;
}
vector <int> go1(vector <int> v)
{
    vector <int> z;
    z.push_back(-1e18);
    z.push_back(-1e18);
    for(int i=v.size()-1;i>=0;i--)
    {
        z.push_back(max(z.back(),v[i]));
    }
    reverse(z.begin(),z.end());
    return z;
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
        int sum0=0,sum1=0;
        vector <int> pr0,pr1;
        bool h=true;
        int curr=0;
        for(int i=0;i<n;i+=2) sum0+=a[i];
        for(int i=1;i<n;i+=2) sum1+=a[i];
        h=(sum0==sum1);
        for(int i=0;i<n;++i)
        {
            if(i%2==0)
            {
                curr-=a[i];
                pr0.push_back(curr);
                h=(h && curr<=0);
            }
            else
            {
                curr+=a[i];
                pr1.push_back(curr);
                h=(h && curr>=0);
            }
        }
        vector <int> ma0=go1(pr0);vector <int> ma1=go2(pr1);
        if(h)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool z=false;
        int curr1=0;
        for(int i=0;i<(n-1);++i)
        {
            if(curr1<0 && i%2==0) break;
            if(curr1>0 && i%2==1) break;
            if(i%2==0)
            {
                curr1-=a[i];
                if((sum1-sum0)!=(2*(a[i+1]-a[i])))
                {
                    continue;
                }
                bool z1=true;
                z1=(z1 && ma0[i/2+1]<=(2*(a[i+1]-a[i])) && pr0[i/2]<=(a[i+1]-a[i]));
                z1=(z1 && ma1[i/2]>=(2*(a[i+1]-a[i])));
                z=(z || z1);
            }
            if(i%2==1)
            {
                curr1+=a[i];
                if((sum0-sum1)!=(2*(a[i+1]-a[i])))
                {
                    continue;
                }
                bool z1=true;
                //cout<<pr1[0]<<endl;
                //cout<<pr0[0]<<' '<<pr0[1]<<endl;
                z1=(z1 && ma1[i/2+1]>=(2*(a[i]-a[i+1])) && pr1[i/2]>=(a[i]-a[i+1]));
                z1=(z1 && ma0[(i+1)/2]<=(2*(a[i]-a[i+1])));
                z=(z || z1);
            }
        }
        if(z) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}