#include <bits/stdc++.h>

using namespace std;
#define int long long
int mex(vector <int> v)
{
    if(v.empty())
    {
        return 0;
    }
    sort(v.begin(),v.end());
    bool h[4];
    for(int i=0;i<4;++i)
    {
        h[i]=false;
    }
    for(int i=0;i<v.size();++i)
    {
        h[v[i]]=true;
    }
    for(int i=0;i<4;++i)
    {
        if(!h[i])
        {
            return i;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    int per=(x+y)*(y+z)*(x+z)*2*x;
    vector <int> v;
    int nimber[per][3];
    for(int i=0;i<per;++i)
    {
        for(int j=0;j<3;++j)
        {
            v.clear();
            if(i!=0)
            {
                v.push_back(nimber[max(i-x,0LL)][0]);
            }
            if(j!=1 && i!=0)
            {
                v.push_back(nimber[max(i-y,0LL)][1]);
            }
            if(j!=2 && i!=0)
            {
                v.push_back(nimber[max(i-z,0LL)][2]);
            }
            nimber[i][j]=mex(v);
        }
    }
    /*for(int i=0;i<=10;++i)
    {
        for(int j=0;j<3;++j)
        {
            cout<<i<<" "<<j<<" "<<nimber[i][j]<<endl;
        }
    }*/
    vector <int> a(n);
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>=(per/2))
        {
            a[i]=(per/2)+(a[i]%(per/2));
        }
        s^=nimber[a[i]][0];
    }
    v.clear();
    v.push_back(x);v.push_back(y);v.push_back(z);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            int h=s^(nimber[a[i]][0]);
            int t=nimber[max(a[i]-v[j],0LL)][j];
            if(h==t)
            {
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}