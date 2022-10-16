#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector< set<int> > in(n), out(n);
        vector<int> ans;
        for (int i=0;i<m;i++)
        {
            int a, b;
            cin>>a>>b;
            a--; b--;
            in[b].insert(a);
            out[a].insert(b);
        }
        for (int i=0;i<n;i++)
        {
            for (auto x : in[i])
            {
                if (in[x].size() > 0)
                {
                    ans.pb(i);
                    for (auto y : out[i])
                    {
                        in[y].erase(in[y].find(i));
                    }
                    out[i].clear();
                    in[i].clear();
                    break;
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" ";
            cout<<'\n';
    }
}