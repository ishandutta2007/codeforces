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
        int n,m;
        cin>>n>>m;
        set<pii> bad;
        map<int,int> cnt;
        while(n--)
        {
            int a;
            cin>>a;
            cnt[a]++;
            bad.insert({a,a});
        }
        map<int,vector<int>> same;
        for(auto[a,c]:cnt)
            same[c].push_back(a);
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            bad.insert({x,y});
            bad.insert({y,x});
        }
        for(auto&[c,v]:same)
            sort(v.begin(),v.end(),greater<>());
        int ans=0;
        for(auto&[c1,v1]:same)
            for(auto&[c2,v2]:same)
                if(c1<=c2)
                    for(int a1:v1)
                    {
                        bool first=true;
                        for(int a2:v2)
                        {
                            if(!bad.count(pair{a1,a2}))
                            {
                                ans=max(ans,(c1+c2)*(a1+a2));
                                break;
                            }
                            first=false;
                        }
                        if(first)
                            break;
                    }
        cout<<ans<<"\n";
    }
}