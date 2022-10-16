#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int mex(vector<int> used)
{
    int index;
    for(int i=0;i<=used.size();i++)
    {
        if(used[i]==0)
        {
            index=i;
            break;
        }
    }
    return index;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        map<int,int> m;
        multiset<int> s;
        for(int i=0;i<=n;i++) s.insert(i); 
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]]++;
            auto it=s.find(v[i]);
            if(it!=s.end())
                s.erase(it);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(v[i]==i) continue;
            auto it=s.begin();
            int mn=*it;
            if(mn==i)
            {
                ans.pb(i);
                m[mn]++;
                it=s.begin();
                s.erase(it);
                m[v[i]]--;
                if(m[v[i]]==0) s.insert(v[i]);
                v[i]=i;

                continue;
            }
                while(mn!=i)
                {
                    if(mn==n)
                    {
                        ans.pb(i);
                        m[mn]++;
                        it=s.begin();
                        s.erase(it);
                        m[v[i]]--;
                        if(m[v[i]]==0) s.insert(v[i]);
                        v[i]=mn;
                        it=s.begin();
                        mn=*it;       
                    }
                    ans.pb(mn);
                    m[v[mn]]--;
                    m[mn]++;
                    it=s.begin();
                    s.erase(it);
                    if(m[v[mn]]==0) s.insert(v[mn]);
                    v[mn]=mn;
                    it=s.begin();
                    mn=*it;
                }
                ans.pb(i);
                m[mn]++;
                m[v[i]]--;
                it=s.begin();
                s.erase(it);
                if(m[v[i]]==0) s.insert(v[i]);
                v[i]=i;
        }
        cout<<ans.size()<<'\n';
        for(auto x: ans) cout<<x+1<<" ";
            cout<<'\n';
    }
}