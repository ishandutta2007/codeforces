#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> pr;
bool prime(int x)
{
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u);
    }
    if(b%2==1)
    {
        int u=po(a,b-1);
        return (a*u);
    }
}
map <int,int> m;
vector <int> keys;
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=2;i<5000;++i)
    {
        if(prime(i))
        {
            pr.push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
    m.clear();keys.clear();
    int left=0;
    vector <pair<int,int> > h;
    for(int i=0;i<22;++i)
    {
        int q=1;
        vector <pair<int,int> > v;
        for(int j=0;j<h.size();++j)
        {
            q*=po(h[j].first,h[j].second);
            v.push_back(h[j]);
        }
        while(q<(1e18/pr[left]))
        {
            q*=pr[left];
            v.push_back({pr[left],1});
            ++left;
        }
        cout<<"? "<<q<<endl;
        int ans;
        cin>>ans;
        h.clear();
        for(int j=0;j<v.size();++j)
        {
            int x=po(v[j].first,v[j].second);
            if(ans%x==0)
            {
                //cout<<x<<" x "<<endl;
                if(!m.count(v[j].first))
                {
                    keys.push_back(v[j].first);
                    m[v[j].first]=v[j].second;
                }
                else
                {
                    m[v[j].first]=v[j].second;
                }
                //cout<<v[j].first<<" "<<v[j].second+1<<endl;
                h.push_back({v[j].first,v[j].second+1});
            }
        }
    }
    //cout<<pr[left]<<" pr[left] "<<endl;
    int ans=1;
    for(int i=0;i<keys.size();++i)
    {
        ans*=(m[keys[i]]+1);
    }
    cout<<"! "<<2*ans<<endl;
    }
    return 0;
}