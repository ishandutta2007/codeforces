#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l,r;
    cin>>l>>r;
    int n=32;
    vector <pair<int,pair<int,int> > > v;
    int po[32];
    po[0]=1;
    po[1]=1;
    for(int i=2;i<32;++i) po[i]=2*po[i-1];
    for(int i=0;i<31;++i)
    {
        for(int j=(i+1);j<31;++j)
        {
            v.push_back({po[i],{i+1,j+1}});
        }
    }
    while(true)
    {
        int x=(r-l+1);
        if(x<=0) break;
        int sz=1;
        int o=1;
        while(sz<=x)
        {
            sz*=2;
            ++o;
        }
        sz/=2;
        o--;
        if(r!=sz)
        {
        v.push_back({r-sz,{o+1,32}});
        r-=sz;
        }
        else
        {
            for(int i=(o-1);i>=0;i--)
            {
                if(i!=0)
                {
                    sz/=2;
                    v.push_back({r-sz,{i+1,32}});
                    r-=sz;
                }
                else
                {
                    ++r;
                    v.push_back({r-sz,{i+1,32}});
                    r-=sz;
                }
            }
            break;
        }
    }
    cout<<"YES"<<endl;
    cout<<32<<' '<<v.size()<<endl;
    for(auto h:v)
    {
        cout<<h.second.first<<' '<<h.second.second<<' '<<min((int) 1e6,h.first)<<endl;
    }
    return 0;
    return 0;
}