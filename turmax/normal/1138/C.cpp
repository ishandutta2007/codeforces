#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int m;
    cin>>n>>m;
    int k;
    vector <vector <int>  > a;
    for(int i=0;i<n;++i)
    {
        vector <int> h;
        a.push_back(h);
        for(int j=0;j<m;++j)
        {
            cin>>k;
            a[i].push_back(k);
        }
    }
    vector <int> x(m);
    map <int,int> b[n];
    int t;
    int u;
    int m1[n];
    for(int i=0;i<n;++i)
    {
        x=a[i];
        sort(x.begin(),x.end());
        t=1;
        u=x[0];
        b[i][u]=1;
        for(int j=1;j<m;++j)
        {
            if(x[j]>u)
            {
                ++t;
                u=x[j];
            }
            b[i][x[j]]=t;
        }
        m1[i]=t;
    }
    map <int,int> c[m];
    x.resize(n);
    int m2[m];
    for(int i=0;i<m;++i)
    {
        for(int r=0;r<n;++r)
        {
            x[r]=a[r][i];
        }
        sort(x.begin(),x.end());
        t=1;
        u=x[0];
        c[i][u]=1;
        for(int j=1;j<n;++j)
        {
            if(x[j]>u)
            {
                ++t;
                u=x[j];
            }
            c[i][x[j]]=t;
        }
        m2[i]=t;
    }
    int l;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            l=max(b[i][a[i][j]],c[j][a[i][j]]);
            cout<<max(m1[i]-b[i][a[i][j]]+l,m2[j]-c[j][a[i][j]]+l)<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}