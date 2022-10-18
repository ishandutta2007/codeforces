#include<bits/stdc++.h>

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
        int a,b,q;
        cin>>a>>b>>q;
        if(a>b)
            swap(a,b);
        int lcm=a/__gcd(a,b)*b;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int mn=l/lcm*lcm;
            int mx=r/lcm*lcm;
            set<int> check{mn,mx};
            int ans=(mx-mn)/lcm+1-check.size();
            ans*=b;
            for(int from:check)
            {
                int to=from+b-1;
                int len=min(to,r)-max(from,l)+1;
                len=max(len,0ll);
                ans+=len;
            }
            cout<<r-l+1-ans<<" ";
        }
        cout<<"\n";
    }
}