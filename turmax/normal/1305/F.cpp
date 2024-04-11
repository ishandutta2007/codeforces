#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int,int> u;
int go(vector <int> &a,int p)
{
    //cout<<p<<" p "<<endl;
    if(u.count(p))
    {
        return u[p];
    }
    int n=a.size();
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]>=p)
        sum+=min(a[i]%p,(p-a[i]%p));
        else
        sum+=(p-a[i]);
    }
    u[p]=sum;
    //cout<<sum<<" sum "<<endl;
    return sum;
}
vector <int> rasl(int n)
{
    vector <int> v;
    if(n<=1)
    {
        return v;
    }
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int s=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    srand(time(NULL));
    int ans=1e18;
    for(int i=0;i<20;++i)
    {
        int x=(rand()+rand()*32768)%n;
        int y=a[x];
        vector <int> v1=rasl(y);
        vector <int> v2=rasl(y+1);
        vector <int> v3=rasl(y-1);
        for(int i=0;i<v1.size();++i)
        {
            ans=min(ans,go(a,v1[i]));
        }
        for(int i=0;i<v2.size();++i)
        {
            ans=min(ans,go(a,v2[i]));
        }
        for(int i=0;i<v3.size();++i)
        {
            ans=min(ans,go(a,v3[i]));
        }
    }
    cout<<ans+s;
    return 0;
}