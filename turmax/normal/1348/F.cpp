#include <bits/stdc++.h>

using namespace std;
#define int long long
bool inotr(int l,int x,int r)
{
    return (x>=l) && (x<r);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];
    vector <pair <int,int> > b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        a[i].first--;
        b[a[i].first].push_back({a[i].second,i});
    }
    int ans[n];
    int u[n];
    set <pair<int,pair <int,int> > > v;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<b[i].size();++j)
        {
            pair <int,int> curr=b[i][j];
            v.insert({curr.first,{i,curr.second}});
        }
        pair <int,pair<int,int> > h=(*v.begin());
        v.erase(h);
        ans[i]=h.second.second;
    }
    for(int i=0;i<n;++i)
    {
        u[ans[i]]=i;
    }
    for(int i=0;i<(n-1);++i)
    {
        if(inotr(a[ans[i]].first,i+1,a[ans[i]].second) && inotr(a[ans[i+1]].first,i,a[ans[i+1]].second))
        {
            cout<<"NO"<<endl;
            for(int i=0;i<n;++i)
            {
                cout<<u[i]+1<<" ";
            }
            cout<<endl;
            swap(ans[i],ans[i+1]);
            for(int i=0;i<n;++i)
            {
                u[ans[i]]=i;
            }
            for(int i=0;i<n;++i)
            {
                cout<<u[i]+1<<" ";
            }
            return 0;
        }
    }
    for(int i=0;i<n;++i)
    {
        sort(b[i].begin(),b[i].end());
        if(b[i].size()>=2)
        {
            int x=u[b[i][1].second];
            if(x<b[i][0].first)
            {
                cout<<"NO"<<endl;
                for(int i=0;i<n;++i)
                {
                    cout<<u[i]+1<<" ";
                }
                cout<<endl;
                swap(ans[x],ans[b[i][0].second]);
                for(int i=0;i<n;++i)
                {
                    u[ans[i]]=i;
                }
                for(int i=0;i<n;++i)
                {
                    cout<<u[i]+1<<" ";
                }
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<u[i]+1<<" ";
    }
    return 0;
}