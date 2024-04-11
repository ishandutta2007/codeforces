#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,u6;
    cin>>n>>m;
    vector <pair<int,int> > v(m);
    for(int i=0;i<m;++i)
    {
        cin>>k;
        v[i].first=k-1;
        cin>>u6;
        v[i].second=u6-1;
    }
    int u;
    int r;
    int p;
    int e;
    int u1;
    for(int i=0;i<n;++i)
    {
        u=i;
        vector <int> a;
        vector <int> b;
        vector <int> c;
        for(int j=0;j<m;++j)
        {
            a.push_back(0);
        }
        for(int j=0;j<m;++j)
        {
            b.push_back(0);
        }
        r=0;
        while(true)
        {
            e=-1;
            for(int y=0;y<m;++y)
            {
                if(v[y].first==u && a[y]==0)
                {
                    if((v[y].second-v[y].first+n)%n>e)
                    {
                        u1=y;
                        e=(v[y].second-v[y].first+n)%n;
                    }
                }
            }
            if(e!=(-1))
            {
                a[u1]=1;
            }
            for(int y=0;y<m;++y)
            {
                if(v[y].second==u && a[y]==1)
                {
                    b[y]=1;
                }
            }
            p=1;
            for(int y=0;y<m;++y)
            {
                if(b[y]==0)
                {
                    p=0;
                }
            }
            if(p==1)
            {
                cout<<r<<" ";
                break;
            }
            ++u;
            ++r;
            u%=n;
        }
    }
    return 0;
}