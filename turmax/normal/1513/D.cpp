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
        int n,p;
        cin>>n>>p;
        int a[n];
        bool ok[n];
        for(int i=0;i<n;++i) {cin>>a[i];ok[i]=true;}
        set <pair <int,int> > d;
        for(int i=0;i<n;++i) d.insert({a[i],i});
        int res=0;
        for(auto h:d)
        {
            int i=h.second;
            if(!ok[i]) continue;
            int r;
            int l;
            for(int j=(i+1);j<=n;++j)
            {
                if(j==n || !ok[j] || (a[j]%a[i])!=0)
                {
                    r=(j-1);
                    break;
                }
            }
            for(int j=(i-1);j>=(-1);--j)
            {
                if(j==(-1) || !ok[j] || (a[j]%a[i])!=0)
                {
                    l=(j+1);
                    break;
                }
            }
            if(l==r)
            {
                ok[i]=false;
                if(i!=0 && ok[i-1]) res+=p;
                if(i!=(n-1) && ok[i+1]) res+=p;
            }
            else
            {
                if(r==i && r!=(n-1) && ok[r+1]) res+=p;
                if(l==i && l!=0 && ok[l-1]) res+=p;
                res+=(r-l)*min(a[i],p);
                ok[i]=false;
                for(int j=(l+1);j<=(r-1);++j)
                {
                    ok[j]=false;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}