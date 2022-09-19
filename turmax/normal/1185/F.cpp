#include <bits/stdc++.h>

using namespace std;
#define int long long
bool check(int l,int k)
{
    for(int i=0;i<9;++i)
    {
        if(((k>>i)%2)==1 && (l>>i)%2==0)
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    int a[512];
    for(int i=0;i<512;++i)
    {
        a[i]=0;
    }
    int b[512];
    int c[512];
    for(int i=0;i<512;++i)
    {
        b[i]=1e9+1;
    }
    int x,y;
    int s;
    vector <pair<int,int> > f;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        s=0;
        for(int i=0;i<x;++i)
        {
            cin>>y;
            s+=(1<<(y-1));
        }
        a[s]+=1;
    }
    int r;
    for(int i=0;i<m;++i)
    {
        cin>>r;
        f.push_back({r,i});
        cin>>x;
        s=0;
        for(int i=0;i<x;++i)
        {
            cin>>y;
            s+=(1<<(y-1));
        }
        if(r<b[s])
        {
            b[s]=r;
            c[s]=i;
        }
    }
    int ma=(-1);
    int l;
    int u1;
    int u2;
    int z;
    for(int i=0;i<512;++i)
    {
        if(b[i]==(1e9+1))
        {
            continue;
        }
        for(int j=0;j<=i;++j)
        {
            s=0;
            if(b[j]==(1e9+1))
            {
                continue;
            }
            l=(i|j);
            for(int k=0;k<512;++k)
            {
                if(check(l,k))
                {
                     s+=a[k];
                }
            }
            if(s>ma || (s==ma && (b[i]+b[j])<z))
            {
                ma=s;
                u1=c[j];
                u2=c[i];
                z=b[i]+b[j];
            }
        }
    }
    if(u1==u2)
    {
        sort(f.begin(),f.end());
        for(int i=0;i<m;++i)
        {
            if(f[i].second!=u1)
            {
                u2=f[i].second;
                break;
            }
        }
    }
    cout<<u1+1<<" "<<u2+1<<endl;
    return 0;
}