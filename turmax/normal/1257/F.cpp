#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int a,int b)
{
    int sum=0;
    int d=a^b;
    for(int i=0;i<30;++i)
    {
        if((d>>i)&1)
        {
            ++sum;
        }
    }
    return sum;
}
vector <int> go(vector <int> a)
{
    int n=a.size();
    vector <int> v(n-1);
    for(int i=1;i<n;++i)
    {
        v[i-1]=a[i]-a[0];
    }
    return v;
}
vector <int> inv(vector <int> a)
{
    int n=a.size();
    vector <int> v(n);
    for(int i=0;i<n;++i)
    {
        v[i]=-a[i];
    }
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    vector <int> c(n);
    vector <vector <int> > b1;
    vector <vector <int> > c1;
    map <vector <int>,int> b2;
    map <vector <int>,int> c2;
    int sz=(1<<15);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i]/sz;
        c[i]=a[i]%sz;
    }
    vector <int> v(n);
    for(int i=0;i<sz;++i)
    {
        for(int j=0;j<n;++j)
        {
            v[j]=f(i,b[j]);
        }
        b1.push_back(go(v));
        b2[go(v)]=i;
    }
    for(int i=0;i<sz;++i)
    {
        for(int j=0;j<n;++j)
        {
            v[j]=f(i,c[j]);
        }
        c1.push_back(go(v));
        c2[go(v)]=i;
    }
    vector <int> u1;
    vector <int> u2;
    for(int i=0;i<sz;++i)
    {
        u1=c1[i];
        u2=inv(u1);
        if(b2.count(u2)==1)
        {
            cout<<b2[u2]*sz+i;
            return 0;
        }
    }
    cout<<(-1);
    return 0;
}