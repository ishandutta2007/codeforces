#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,h,m,k;
    cin>>n>>h>>m>>k;
    vector <pair<int,int> > v;
    vector <pair<int,int> > v1;
    int m1=(m/2);
    for(int i=0;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        b%=m1;
        v.push_back({b,i});
        v1.push_back({b,i});v1.push_back({b+m1,i});
    }
    sort(v1.begin(),v1.end());
    int ans=1e18;
    int i1=0;
    int t1,t2;
    for(int i=0;i<v1.size();++i)
    {
        pair <int,int> z=v1[i];
        int ans1;
        if(z.first>=m1)
        {
            continue;
        }
        ans1=lower_bound(v1.begin(),v1.end(),make_pair(z.first+k,(int) -1e18))-v1.begin()-i-1;
        if(ans1<ans)
        {
            ans=ans1;
            i1=i;
            t1=z.first;
            t2=z.first+k;
        }
    }
    //cout<<ans<<" ans "<<endl;
    {
        vector <int> g;
        for(auto z:v1)
        {
            if(z.first>t1 && z.first<t2)
            {
                g.push_back(z.second);
            }
        }
        cout<<g.size()<<' '<<(t1+k)%m1<<endl;
        for(auto v:g)
        {
            cout<<v+1<<' ';
        }
        return 0;
    }
    return 0;
}