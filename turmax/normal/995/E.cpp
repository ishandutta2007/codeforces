#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e4;
int po(int a,int b,int p)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2,p);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1,p);
        return (a*u)%p;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    int u,v,p;
    cin>>u>>v>>p;
    vector <pair<int,vector <int> > > vu;
    vector <pair<int,vector <int> > > vv;
    for(int i=0;i<maxn;++i)
    {
        /*if(i%10000==0)
        {
            cout<<i<<" i "<<endl;
        }*/
        vector <int> h;
        int curr=u;
        for(int i=0;i<40;++i)
        {
            h.push_back(rand()%3);
            if(h.back()==0)
            {
                ++curr;
                curr%=p;
            }
            else if(h.back()==1)
            {
                curr+=(p-1);
                curr%=p;
            }
            else
            {
                curr=po(curr,p-2,p);
            }
        }
        vu.push_back({curr,h});
        h.clear();
        curr=v;
        for(int i=0;i<40;++i)
        {
            h.push_back(rand()%3);
            if(h.back()==0)
            {
                curr+=(p-1);
                curr%=p;
            }
            else if(h.back()==1)
            {
                curr++;
                curr%=p;
            }
            else
            {
                curr=po(curr,p-2,p);
            }
        }
        vv.push_back({curr,h});
    }
    sort(vv.begin(),vv.end());
    //cout<<" ytrf "<<endl;
    vv.push_back({1e18,{}});
    for(auto z:vu)
    {
        pair <int,vector <int> > o=(*lower_bound(vv.begin(),vv.end(),z));
        if((o.first-z.first)<=100)
        {
            vector <int> res=z.second;
            for(int i=0;i<(o.first-z.first);++i)
            {
                res.push_back(0);
            }
            reverse(o.second.begin(),o.second.end());
            for(auto l:o.second)
            {
                res.push_back(l);
            }
            cout<<res.size()<<endl;
            for(auto l:res)
            {
                cout<<(l+1)<<' ';
            }
            return 0;
        }
    }
    return 0;
}