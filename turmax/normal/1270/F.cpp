#include <bits/stdc++.h>

using namespace std;
#define int long long
int to(int a,int l,int r)
{
    if(a<0)
    {
        return 0;
    }
    if(l>r)
    {
        swap(l,r);
    }
    if(a<=l)
    {
        return (a+1);
    }
    if(a<=r)
    {
        return l+1;
    }
    return (l+r-a+1);
}
int go(int curr,int l,int r,int x)
{
    int sum=0;
    for(int i=110;(i*x)<=(curr+l+r);++i)
    {
        sum+=to(i*x-curr,l,r);
    }
    //cout<<sum<<" sum "<<endl;
    return sum;
}
int a[200005];
int b[200005];
unordered_map <int,int> o;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    vector <int> v;
    a[0]=0;
    b[0]=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            v.push_back(i);
        }
        a[i+1]=a[i]+1;
        b[i+1]=b[i]+(s[i]-'0');
    }
    vector <int> d;
    int ans=0;
    int u;
    for(int i=1;i<110;++i)
    {
        //cout<<i<<endl;
        o.clear();
        d.clear();
        for(int j=0;j<(n+1);++j)
        {
            u=a[j]-i*b[j];
            d.push_back(u);
            if(o.count(u)==0)
            {
                o[u]=1;
            }
            else
            {
                o[u]++;
            }
        }
        //cout<<i<<endl;
        for(int j=0;j<(n+1);++j)
        {
            //cout<<(o[d[j]]-1)<<" grfdesa "<<endl;
            ans+=(o[d[j]]-1);
        }
        //cout<<ans<<endl;
        //cout<<i<<endl;
    }
    ans/=2;
    //cout<<ans<<endl;
    v.push_back(-1);
    v.push_back(n);
    sort(v.begin(),v.end());
    /*for(int i=0;i<v.size()-1;++i)
    {
        ans-=500*((v[i+1]-v[i])*(v[i+1]-v[i]-1)/2);
        //cout<<ans<<endl;
    }*/
    //int sum=0;
    for(int i=1;i<v.size()-1;++i)
    {
        for(int j=0;j<min((int) (v.size()-i-1),1820LL);++j)
        {
            //++sum;
            //cout<<v[i+j]-v[i]+1<<" "<<v[i+j+1]-v[i+j]-1<<" "<<v[i]-v[i-1]-1<<" "<<j+1<<endl;
            ans+=go(v[i+j]-v[i]+1,v[i+j+1]-v[i+j]-1,v[i]-v[i-1]-1,j+1);
        }
    }
    //cout<<sum<<endl;
    cout<<ans;
    return 0;
}