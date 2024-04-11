#include <bits/stdc++.h>

using namespace std;
#define int long long
int s[200001];
int lcm(int x,int y)
{
    return x*y/__gcd(x,y);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int j=1;j*j<=a[i];++j)
        {
            if(a[i]%j==0)
            {
                s[j]++;
                if(a[i]!=(j*j))
                {
                    s[a[i]/j]++;
                }
            }
        }
    }
    int ans=1;
    for(int x=1;x<=200000;++x)
    {
        if(s[x]>=(n-1))
        {
            //cout<<x<<" s[x] "<<s[x]<<endl;
            ans=lcm(ans,x);
        }
    }
    cout<<ans;
    return 0;
}