#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> v1(n);
    vector <int> h;
    for(int i=0;i<n;++i)
    {
        cin>>v1[i];
        h.push_back(v1[i]);
    }
    vector <int> v2(n);
    for(int i=0;i<n;++i)
    {
        cin>>v2[i];
    }
    unordered_map <int,vector <int> > u;
    for(int i=0;i<n;++i)
    {
        if(u.count(v1[i]))
        {
            u[v1[i]].push_back(v2[i]);
        }
        else
        {
            vector <int> z;
            z.clear();
            z.push_back(v2[i]);
            u[v1[i]]=z;
        }
    }
    sort(h.begin(),h.end());
    int curr=(-1);
    set <int> o;
    int ans=0;
    int s=0;
    unordered_map <int,int> d;
    while(true)
    {
        //cout<<curr<<" "<<o.size()<<" "<<ans<<endl;
        if(u.count(curr))
        {
            vector <int> v=u[curr];
            //cout<<v.size()<<" tgfrdesw "<<endl;
            for(int i=0;i<v.size();++i)
            {
                o.insert(-v[i]);
                if(d.count(-v[i]))
                {
                    d[-v[i]]++;
                }
                else
                {
                    d[-v[i]]=1;
                }
                s+=v[i];
            }
        }
        if(o.empty())
        {
            if(curr>h[h.size()-1])
            {
                break;
            }
            curr=h[upper_bound(h.begin(),h.end(),curr)-h.begin()];
            continue;
        }
        else
        {
            //cout<<s<<" s "<<endl;
            int x=(*o.begin());
            if(s==(-x))
            {
                d[x]--;
                s=0;
                o.clear();
            }
            else
            {
                s+=x;
                //cout<<s<<" rfde sw"<<endl;
                ans+=s;
                d[x]--;
                if(!d[x])
                o.erase(o.begin());
            }
        }
        ++curr;
    }
    cout<<ans<<endl;
    return 0;
}