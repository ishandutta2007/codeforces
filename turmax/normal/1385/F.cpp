#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    vector <int> a[n];
    vector <int> v[n];
    int deq[n];
    bool used[n];
    int is[n];
    for(int i=0;i<n;++i) {deq[i]=0;used[i]=false;is[i]=0;}
    vector <int> d;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        deq[x]++;deq[y]++;
    }
    if(k==1)
    {
        cout<<(n-1)<<endl;
        continue;
    }
    for(int i=0;i<n;++i)
    {
        if(deq[i]==1)
        {
            v[a[i][0]].push_back(i);
            is[a[i][0]]++;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(is[i]>=k)
        {
            d.push_back(i);
        }
    }
    int ans=0;
    //cout<<d.size()<<" size "<<endl;
    while(!d.empty())
    {
        int x=d.back();d.pop_back();
        //cout<<x<<" x "<<endl;
        if(used[x])
        {
            continue;
        }
        ++ans;
        for(int i=0;i<k;++i)
        {
            int h=v[x].back();
            v[x].pop_back();
            used[h]=true;
            is[x]--;
            deq[x]--;
        }
        if(is[x]>=k)
        {
            d.push_back(x);
        }
        if(deq[x]==1)
        {
            for(auto l:a[x])
            {
                if(!used[l])
                {
                    v[l].push_back(x);
                    is[l]++;
                    if(is[l]==k)
                    {
                        d.push_back(l);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}