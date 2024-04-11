#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1000;
vector <int> a[maxn];
int deq[maxn];
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        deq[x]++;deq[y]++;
    }
    vector <pair<int,int> > d;
    for(int i=0;i<n;++i)
    {
        d.push_back({deq[i],i});
    }
    bool used[n];
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    for(int i=0;i<(n/2);++i)
    {
        d.clear();
        for(int i=0;i<n;++i)
        {
            if(!used[i])
        d.push_back({deq[i],i});
        }
        //cout<<deq[5]<<" deq[5] "<<endl;
        sort(d.begin(),d.end());
        int x=d[0].second;
        int y=d[1].second;
        cout<<"? "<<x+1<<" "<<y+1<<endl;
        int ans;
        cin>>ans;
        ans--;
        if(ans==x)
        {
            cout<<"! "<<x+1<<endl;
            exit(0);
        }
        if(ans==y)
        {
            cout<<"! "<<y+1<<endl;
            exit(0);
        }
        d.erase(d.begin());
        d.erase(d.begin());
        deq[x]--;deq[y]--;
        for(int i=0;i<a[x].size();++i)
        {
            if(!used[a[x][i]])
            {
                deq[a[x][i]]--;
            }
        }
        for(int i=0;i<a[y].size();++i)
        {
            if(!used[a[y][i]])
            {
                deq[a[y][i]]--;
            }
        }
        used[x]=true;
        used[y]=true;
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            cout<<"! "<<i+1<<endl;
            exit(0);
        }
    }
    return 0;
}