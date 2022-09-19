#include <bits/stdc++.h>

using namespace std;
#define int long long
int query(vector <int> v)
{
    cout<<"? ";
    cout<<v.size()<<" ";
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    cout<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int go(vector <int> v,int ma)
{
    if(v.size()==1)
    {
        return v[0];
    }
    vector <int> g;
    for(int i=0;i<v.size()/2;++i)
    {
        g.push_back(v[i]);
    }
    int ma2=query(g);
    if(ma==ma2)
    {
        return go(g,ma);
    }
    else
    {
        vector <int> h;
        for(int i=v.size()/2;i<v.size();++i)
        {
            h.push_back(v[i]);
        }
        return go(h,ma);
    }
}
void get(vector <int> res)
{
    cout<<"! ";
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    string s;
    cin>>s;
    if(s=="Correct")
    {
        return;
    }
    else
    {
        exit(0);
    }
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,c;
    cin>>n>>c;
    int h[n]; for(int i=0;i<n;++i) h[i]=(-1);
    for(int i=0;i<c;++i)
    {
        int l;
        cin>>l;
        for(int j=0;j<l;++j)
        {
            int x;
            cin>>x;
            x--;
            h[x]=i;
        }
    }
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        v.push_back(i);
    }
    int ma=query(v);
    int ans=go(v,ma);
    vector <int> res(c);
    for(int i=0;i<c;++i)
    {
        if(h[ans]!=i)
        {
            res[i]=ma;
        }
    }
    int o=h[ans];
    if(o==(-1))
    {
        get(res);
    }
    else
    {
        vector <int> u;
        for(int i=0;i<n;++i)
        {
            if(h[i]!=h[ans])
            {
                u.push_back(i);
            }
        }
        int ma2=query(u);
        res[h[ans]]=ma2;
        get(res);
    }
    }
    return 0;
}