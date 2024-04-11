#include <bits/stdc++.h>

using namespace std;
#define int long long
int mul(int a,int b,int p)
{
    if(b==0) return 0;
    if(b==1) return a%p;
    if(b%2==0)
    {
        int u=mul(a,b/2,p);
        return (u+u)%p;
    }
    else
    {
        int u=mul(a,b-1,p);
        return (a+u)%p;
    }
}
int po(int a,int b,int p)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2,p);
        return mul(u,u,p);
    }
    else
    {
        int u=po(a,b-1,p);
        return mul(a,u,p);
    }
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1) return v;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
int fi(int x)
{
    vector <int> v=rasl(x);
    sort(v.begin(),v.end());
    int ans=1;
    for(int i=0;i<v.size();++i)
    {
        if(i==0 || v[i]!=v[i-1])
        {
            ans*=(v[i]-1);
        }
        else
        {
            ans*=v[i];
        }
    }
    return ans;
}
int inv(int x,int y)
{
    return po(x,fi(y)-1,y);
}
pair <int,int> go1(pair <int,int> a,pair <int,int> b)
{
    int u=mul(((b.first-a.first)%b.second+b.second)%b.second,inv(a.second,b.second),b.second);
    u%=b.second;
    u+=b.second;
    u%=b.second;
    int m=a.second*b.second;
    return {((mul(u,a.second,m)+a.first)%m+m)%m,m};
}
int t(int x,int p)
{
    int ans=1;
    while(x%p==0)
    {
        ans*=p;
        x/=p;
    }
    return ans;
}
pair <int,int> go(pair <int,int> a,pair<int,int> b)
{
    int d=__gcd(a.second,b.second);
    int x=(a.first%d);
    if(b.first%d!=x)
    {
        cout<<"NO";
        exit(0);
    }
    int u1=a.second;int u2=b.second;
    vector <int> v=rasl(d);
    for(auto h:v)
    {
        //cout<<u1<<" "<<u2<<" "<<h<<endl;
        int o1=t(u1,h);int o2=t(u2,h);
        //cout<<o1<<" "<<o2<<endl;
        if(o1>=o2)
        {
            u2/=o2;
        }
        else
        {
            u1/=o1;
        }
    }
    return go1({a.first%u1,u1},{b.first%u2,u2});
}
int gcy(int x,int y)
{
    int d=__gcd(x,y);
    y/=d;
    if(x>=(2e18/y))
    {
        cout<<"NO";
        exit(0);
    }
    return x*y;
}
int32_t main()
{
    //pair <int,int> r=go({1e5-1,1e5},{1e12-1,1e12});
    //cout<<r.first<<' '<<r.second<<endl;
    //pair <int,int> r=go({2,100},{4,6});
    //cout<<r.first<<' '<<r.second<<endl;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int a[k];
    int h=1;
    for(int i=0;i<k;++i) {cin>>a[i];h=gcy(h,a[i]);}
    if(h>n)
    {
        cout<<"NO";
        return 0;
    }
    pair <int,int> z={0,1};
    //cout<<z.first<<' '<<z.second<<" z "<<endl;
    for(int i=0;i<k;++i)
    {
        z=go(z,{((((a[i]-i)%a[i])+a[i])%a[i]),a[i]});
    }
    int f=z.first;
    //cout<<z.first<<' '<<z.second<<" z "<<endl;
    if(f==0) f+=h;
    if(f<0)
    {
        cout<<"NO";
        return 0;
    }
    if((f+k-1)>m)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<k;++i)
    {
        if(__gcd(i+f,h)!=a[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}