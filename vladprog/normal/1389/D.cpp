#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k,l1,r1,l2,r2;
        cin>>n>>k>>l1>>r1>>l2>>r2;
        int L=min(l1,l2),
            l=max(l1,l2),
            r=min(r1,r2),
            R=max(r1,r2);
        int mn=max(0ll,r-l);
        int mx=R-L;
        int start=mn*n;
        int cost=max(0ll,l-r);
        int ans=1e18;
        int now=start,res=0;
        for(int i=1;i<=n;i++)
        {
            if(now>=k)
                break;
            res+=cost;
            int add=min(k-now,mx-mn);
            now+=add;
            res+=add;
            if(now<k)
                ans=min(ans,res+2*(k-now));
        }
        if(now>=k)
            ans=min(ans,res);
        cout<<ans<<"\n";
    }
}