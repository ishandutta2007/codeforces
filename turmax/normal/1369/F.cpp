#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> v;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    pair <bool,bool> ans[t];
    int curr=0;
    for(int cyc=0;cyc<t;++cyc)
    {
    v.clear();
    int s,e;
    cin>>s>>e;
    v.push_back(e);
    v.push_back(e-1);
    int x=e;
    while(x>s)
    {
        x=(x+2)/2;
        if(x>=s)
        {
            v.push_back(x);
            v.push_back(x-1);
            v.push_back(x+1);
        }
        x--;
    }
    v.push_back(s);
    v.push_back(s+1);
    sort(v.begin(),v.end());
    vector <int> g=v;
    reverse(v.begin(),v.end());
    bool dp1[v.size()];
    for(int i=0;i<v.size();++i)
    {
        if(v[i]==e)
        {
            dp1[i]=false;
            continue;
        }
        if(v[i]==(e-1))
        {
            dp1[i]=true;
            continue;
        }
        if(v[i]>e)
        {
            continue;
        }
        dp1[i]=false;
        int x=v[i];
        if((v[i-1]-v[i])%2==1 && !dp1[i-1])
        {
            dp1[i]=true;
            continue;
        }
        if((v[i-1]-v[i])%2==0 && dp1[i-1])
        {
            dp1[i]=true;
            continue;
        }
        int y=2*v[i];
        if(y<=e)
        {
        int u=upper_bound(g.begin(),g.end(),y)-g.begin()-1;
        for(int j=(g.size()-u-1);j<v.size();++j)
        {
            if(v[j]<=y && (v[j]%2)==(y%2))
            {
                if(!dp1[j])
                dp1[i]=true;
                break;
            }
        }
        }
    }
    bool dp2[v.size()];
    for(int i=0;i<v.size();++i)
    {
        if((2*v[i])>e)
        {
            //cout<<i<<" i "<<endl;
            dp2[i]=true;
            continue;
        }
        dp2[i]=false;
        int x=v[i];
        //cout<<v[i-1]<<" v[i-1] "<<endl;
        if((v[i-1]-v[i])%2==1 && !dp2[i-1])
        {
            dp2[i]=true;
            continue;
        }
        if((v[i-1]-v[i])%2==0 && dp2[i-1])
        {
            dp2[i]=true;
            continue;
        }
        int y=2*v[i];
        int u=upper_bound(g.begin(),g.end(),y)-g.begin()-1;
        for(int j=(g.size()-u-1);j<v.size();++j)
        {
            if(v[j]<=y && (v[j]%2)==(y%2))
            {
                if(!dp2[j])
                dp2[i]=true;
                break;
            }
        }
    }
    pair <bool,bool> h;
    for(int i=0;i<v.size();++i)
    {
        //cout<<i<<" i "<<v[i]<<" v[i] "<<dp2[i]<<" dp2[i] "<<dp1[i]<<" dp1[i] "<<endl;
        if(v[i]==s)
        {
            h={dp1[i],dp2[i]};
            break;
        }
    }
    ans[cyc]=h;
    }
    /*for(int i=0;i<t;++i)
    {
        if(ans[i].first)
        {
            cout<<1<<" ";
        }
        else
        {
            cout<<0<<" ";
        }
        if(ans[i].second)
        {
            cout<<1<<" ";
        }
        else
        {
            cout<<0<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    bool dp1[t+1];
    dp1[t]=false;
    bool dp2[t+1];
    dp2[t]=true;
    for(int i=(t-1);i>=0;i--)
    {
        dp1[i]=false;
        if(ans[i].first)
        {
            dp1[i]=(dp1[i] || !dp1[i+1]);
        }
        if(ans[i].second)
        {
            dp1[i]=(dp1[i] || dp1[i+1]);
        }
        dp2[i]=false;
        if(ans[i].first)
        {
            dp2[i]=(dp2[i] || !dp2[i+1]);
        }
        if(ans[i].second)
        {
            dp2[i]=(dp2[i] || dp2[i+1]);
        }
    }
    if(dp1[0])
    {
        cout<<1<<" ";
    }
    else
    {
        cout<<0<<" ";
    }
    if(dp2[0])
    {
        cout<<1<<" ";
    }
    else
    {
        cout<<0<<" ";
    }
    return 0;
}