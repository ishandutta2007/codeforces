#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

#define int ll
vector<pair<int,int>> m,um,ans;
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int sum = 0;
    forii
    {
        double t;
        cin>>t;
        if(t == (int)t) um.push_back({i,(int)t});
        else m.push_back({i,floor(t)});
        sum += floor(t);
    }
    if(sum<=0 && sum+m.size()>=0)
    {
        int num = -sum;
        for(int i=0;i<m.size();++i)
        {
            if(num--) m[i].second=m[i].second+1;
            else break;
        }
        for(auto p:m) ans.push_back(p);
        for(auto p:um) ans.push_back(p);
        sort(ans.begin(),ans.end());
        for(auto p:ans)
        {
            cout<<p.second<<endl;
        }
    }
    else assert(0);
}