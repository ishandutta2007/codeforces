#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=15010;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pii> ans;
    for(int i=1;(1<<i)<=n;i++)
        for(int l=1,r=(1<<i);r<=n;l=r+1,r+=(1<<i))
            for(int x=l,y=r;x<y;x++,y--)
                ans.push_back({x,y});
    vector<int> v[15];
    int t=n;
    for(int i=0;i<15;i++)
        if((n>>i)&1)
        {
            for(int j=t;j>t-(1<<i);j--)
                v[i].push_back(j);
            t-=(1<<i);
        }
    int last=-1;
    for(int i=0;i<15;i++)
        if(!v[i].empty())
            last=i;
    vector<int> cur;
    for(int i=0;i<last;i++)
    {
        if(v[i].empty())
            swap(v[i],cur);
        if(v[i].empty())
            continue;
        if(cur.empty())
        {
            while(cur.size()<v[i].size())
                cur.push_back(v[last].back()),
                v[last].pop_back();
        }
        assert(v[i].size()==cur.size());
        for(int j=0;j<v[i].size();j++)
            ans.push_back({v[i][j],cur[j]});
        while(!v[i].empty())
            cur.push_back(v[i].back()),
            v[i].pop_back();
    }
    cout<<ans.size()<<"\n";
    for(auto p:ans)
        cout<<p.x<<" "<<p.y<<"\n";
}