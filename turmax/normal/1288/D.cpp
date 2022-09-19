#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
vector <vector <int> > a;
int n,m;
pair <pair<int,int>,bool> go(int k)
{
    vector <vector <int> > b;
    b.resize(n);
    set <vector<int> > d;
    for(int i=0;i<n;++i)
    {
        b[i].resize(m);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]<k)
            {
                b[i][j]=0;
            }
            else
            {
                b[i][j]=1;
            }
        }
    }
    /*for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector <pair<vector <int>,int> > u;
    for(int i=0;i<n;++i)
    {
        if(!d.count(b[i]))
        {
            u.push_back({b[i],i});
        }
        d.insert(b[i]);
    }
    vector <int> v1;
    vector <int> v2;
    vector <int> v;
    bool z;
    for(int i=0;i<u.size();++i)
    {
        for(int j=0;j<=i;++j)
        {
            v1=u[i].first;
            v2=u[j].first;
            v.resize(m);
            z=true;
            for(int k=0;k<m;++k)
            {
                v[k]=max(v1[k],v2[k]);
                if(v[k]==0)
                {
                    z=false;
                    break;
                }
            }
            if(z)
            {
                return {{u[i].second,u[j].second},true};
            }
        }
    }
    return {{-1,-1},false};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    a.resize(n);
    int x;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
        cin>>x;
        a[i].push_back(x);
        }
    }
    int low=(-1);
    int up=(1e9+1);
    int k;
    pair <pair<int,int>,bool> h;
    pair <pair<int,int>,bool> t;
    while(true)
    {
        if((up-low)==1)
        {
            break;
        }
        k=(low+up)/2;
        h=go(k);
        if(h.second)
        {
            t=h;
            low=k;
        }
        else
        {
            up=k;
        }
    }
    cout<<t.first.first+1<<" "<<t.first.second+1;
    return 0;
}