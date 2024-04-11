#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int u,v;
    vector <int> a;
    vector <pair<int,int> > c;
    vector <int> d;
    for(int i=0;i<q;++i)
    {
        a.clear();
        int n,m;
        cin>>n>>m;
        d.resize(3*n);
        for(int i=0;i<3*n;++i)
        {
            d[i]=0;
        }
        for(int i=0;i<m;++i)
        {
            cin>>u>>v;
            u--;
            v--;
            c.push_back({u,v});
            c.push_back({v,u});
            if(d[u]==0 && d[v]==0)
            {
                a.push_back(i+1);
                d[u]=1;
                d[v]=1;
            }
        }
        if(a.size()>=n)
        {
            cout<<"Matching"<<endl;
            for(int i=0;i<n;++i)
            {
                cout<<a[i]<<" ";
            }
            cout<<""<<endl;
        }
        else
        {
            cout<<"IndSet"<<endl;
            int o=0;
            for(int i=0;i<3*n;++i)
            {
                if(o<n)
                {
                    if(d[i]==0)
                    {
                        cout<<(i+1)<<" ";
                        ++o;
                    }
                }
            }
            cout<<""<<endl;
        }
    }
    return 0;
}