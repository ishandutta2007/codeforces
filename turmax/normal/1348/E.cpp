#include <bits/stdc++.h>

using namespace std;
#define int long long
bool l(int x,int y,int k,int x1)
{
    int u=(x+y)%k;
    if((x+y)==u)
    {
        return x==x1;
    }
    if(x1>x)
    {
        return false;
    }
    int z=(x-x1)%k;
    if(y>=((k-z)%k))
    {
        return true;
    }
    else
    {
        return false;
    }
}
vector <int> vx(int x,int y,int k)
{
    vector <int> v;
    for(int i=0;i<k;++i)
    {
        if(l(x,y,k,i))
        {
            v.push_back(i);
        }
    }
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    pair <int,int> a[n];
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        s+=a[i].first;s+=a[i].second;
    }
    int mi=0;
    int ma=0;
    vector <bool> a1(k);
    for(int i=0;i<k;++i)
    {
        a1[i]=false;
    }
    a1[0]=true;
    for(int i=0;i<n;++i)
    {
        //cout<<" new "<<endl;
        vector <bool> b(k);
        for(int i=0;i<k;++i)
        {
            b[i]=false;
        }
        vector <int> v=vx(a[i].first,a[i].second,k);
        for(int i=0;i<v.size();++i)
        {
            //cout<<v[i]<<" v[i] "<<endl;
            for(int j=0;j<k;++j)
            {
                if(a1[j])
                {
                    b[(v[i]+j)%k]=true;
                    //cout<<(v[i]+j)<<" upd "<<endl;
                }
            }
        }
        int s=0;
        for(int i=0;i<k;++i)
        {
            if(b[i])
            {
                ++s;
            }
        }
        a1=b;
        if(s==k)
        {
            break;
        }
    }
    int ans=0;
    for(int i=0;i<k;++i)
    {
        if(a1[i])
        {
            //cout<<i<<" i "<<endl;
        ans=max(ans,i/k+(s-i)/k);
        }
    }
    cout<<ans;
    return 0;
}