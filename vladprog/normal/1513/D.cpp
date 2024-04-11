#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        set<pii> s;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            s.insert({a[i],i});
        int ans=p*(n-1);
        while(!s.empty()&&s.begin()->x<p)
        {
            auto[val,pos]=*s.begin();
            int l=pos,r=pos;
            while(l>1&&a[l-1]%val==0&&s.count({a[l-1],l-1}))
                l--;
            while(r<n&&a[r+1]%val==0&&s.count({a[r+1],r+1}))
                r++;
            for(int i=l;i<=r;i++)
                s.erase({a[i],i});
            ans-=p*(r-l);
            ans+=val*(r-l);
            if(l>1&&a[l-1]%val==0)
                ans-=p,
                ans+=val;
            if(r<n&&a[r+1]%val==0)
                ans-=p,
                ans+=val;
        }
        cout<<ans<<"\n";
    }
}