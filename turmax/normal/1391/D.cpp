#include <bits/stdc++.h>

using namespace std;
#define int long long
int dist(vector <pair<int,int> > v,pair<int,int> c)
{
    int ans=0;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]!=c) ++ans;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <vector <int> > a(n);
    for(int i=0;i<n;++i) a[i].resize(m);
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;++j)
        {
            a[i][j]=s[j]-'0';
        }
    }
    if(n>=4 && m>=4) {cout<<(-1);return 0;}
    if(n>=m)
    {
        vector <vector <int> > b(m);
        for(int i=0;i<m;++i) b[i].resize(n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                b[j][i]=a[i][j];
            }
        }
        a=b;
        swap(n,m);
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    else if(n==2)
    {
        int s0=0;int s1=0;
        for(int i=0;i<m;++i)
        {
            int r=a[0][i]^a[1][i]^(i%2);
            if(r==0) ++s0;
            else ++s1;
        }
        cout<<min(s0,s1);
        return 0;
    }
    else
    {
        vector <pair<int,int> > u(m);
        for(int i=0;i<m;++i)
        {
            u[i]={a[0][i]^a[1][i]^(i%2),a[1][i]^a[2][i]^(i%2)};
        }
        cout<<min(min(dist(u,{0,0}),dist(u,{0,1})),min(dist(u,{1,0}),dist(u,{1,1})));
    }
    return 0;
}