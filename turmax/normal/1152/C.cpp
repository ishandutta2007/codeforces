#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> del(int n)
{
    vector <int> v;
    for(int i=1;(i*i)<=n;++i)
    {
        if((n%i)==0)
        {   if((i*i)!=n)
            {
                v.push_back(i);
                v.push_back(n/i);
            }
            else
            {
                v.push_back(i);
            }
        }
    }
    return v;
}
int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    if(y==0)
    {
        return x;
    }
    if(x>=y)
    {
        return gcd(y,x%y);
    }
    else
    {
        return gcd(y%x,x);
    }
}
int to(int x,int y,int z)
{
    return ((x+z)*(y+z)/gcd(x+z,y+z));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<0;
        return 0;
    }
    int x=abs(a-b);
    int mi=1e18+1;
    vector <int> z=del(x);
    vector <int> v;
    for(int i=0;i<z.size();++i)
    {
        v.push_back((z[i]-(a%z[i])));
    }
    v.push_back(0);
    int l=0;
    int r;
    for(int i=0;i<v.size();++i)
    {
        r=to(a,b,v[i]);
        if(r<mi)
        {
            mi=r;
            l=i;
        }
    }
    cout<<v[l];
    return 0;
}