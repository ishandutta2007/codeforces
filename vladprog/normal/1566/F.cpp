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
vector<pii> group[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        a[0]=-1e18,a[n+1]=1e18;
        for(int i=0;i<=n+1;i++)
            group[i].clear();
        while(m--)
        {
            int l,r;
            cin>>l>>r;
            int g=lower_bound(a,a+n+2,l)-a;
            if(a[g]>r)
                group[g].push_back({l,r});
        }
        int ans[3]={};
        for(int g=1;g<=n+1;g++)
        {
            int L=a[g-1],R=a[g];
            auto&segs=group[g];
//            cout<<"\n";
//            cout<<L<<" .. "<<R<<" :\n";
//            for(auto[l,r]:segs)
//                cout<<l<<" .. "<<r<<"\n";
            if(segs.empty())
            {
                ans[1]=ans[2]=min(ans[1],ans[2]);
                continue;
            }
            sort(segs.begin(),segs.end());
            multiset<int> ends{R};
            for(auto[l,r]:segs)
                ends.insert(r);
            int res[3][3]={};
            for(int i=1;i<=2;i++)
                for(int j=1;j<=2;j++)
                    res[i][j]=min((segs.rbegin()->x-L)*i,(R-*ends.begin())*j);
            for(auto[l,r]:segs)
            {
                ends.erase(ends.find(r));
                for(int i=1;i<=2;i++)
                    for(int j=1;j<=2;j++)
                        res[i][j]=min(res[i][j],(l-L)*i+(R-*ends.begin())*j);
            }
//            for(int i=1;i<=2;i++)
//                for(int j=1;j<=2;j++)
//                    cout<<"res["<<i<<"]["<<j<<"] = "<<res[i][j]<<"\n";
            tie(ans[1],ans[2])=pair(min(ans[1]+res[2][1],ans[2]+res[1][1]),
                                    min(ans[1]+res[2][2],ans[2]+res[1][2]));
//            cout<<"\n";
        }
        cout<<min(ans[1],ans[2])<<"\n";
    }
}