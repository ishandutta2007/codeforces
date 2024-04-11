#include <bits/stdc++.h>

#define vi set<int>
#define iv int, vi
#define ft first
#define sd second

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,k;
    cin>>m>>k;
    map<iv> fr;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        fr[a].insert(b);
        fr[b].insert(a);
    }
    for(pair<iv> i:fr)
    {
        vector<int> ans;
        for(pair<iv> j:fr)
        {
            if(i.ft==j.ft||i.sd.count(j.ft))
                continue;
            int cnt=0;
            for(int t:i.sd)
                if(j.sd.count(t))
                    cnt++;
            if(cnt*100>=i.sd.size()*k)
                ans.push_back(j.ft);
        }
        cout<<i.ft<<": "<<ans.size()<<" ";
        for(int j:ans)
            cout<<j<<" ";
        cout<<"\n";
    }
}