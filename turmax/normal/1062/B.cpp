#include <bits/stdc++.h>

using namespace std;
vector <int> rasl (int n)
{
    if(n==1)
    {
        vector <int> u;
        return u;
    }
    for(int i=2;i<=n;++i)
    {
        if(n%i==0)
        {
            vector <int> u=rasl(n/i);
            u.push_back(i);
            return u;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <int> a=rasl(n);
    map <int,int> f;
    set <int> x;
    int m=0;
    int p=1;
    int u=0;
    for(int i=0;i<a.size();++i)
    {
        if(x.count(a[i])==0)
        {
            p*=a[i];
            x.insert(a[i]);
            f[a[i]]=1;
            m=max(m,f[a[i]]);
        }
        else
        {
            f[a[i]]++;
            m=max(m,f[a[i]]);
        }
    }
    for(int i=0;i<a.size();++i)
    {
        if(f[a[i]]!=m)
        {
            u=1;
        }
    }
    int v=1;
    int l;
    if(p==n)
    {
        cout<<p<<" "<<0;
        return 0;
    }
    for(int i=0;i<1000;++i)
    {
        if(v>m)
        {
            l=i+1;
            break;
        }
        if(v==m)
        {
            l=i+u;
            break;
        }
        v*=2;
    }
    cout<<p<<" "<<l;
    return 0;
}