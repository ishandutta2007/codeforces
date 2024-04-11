#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector <int> a(n);
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        a[i]=s[i]-'0';
    }
    int sum1=0;
    int sum2=0;
    int u=a[0];
    int l=1;
    int v;
    for(int i=1;i<n;++i)
    {
        v=a[i];
        if(u==v)
        {
            ++l;
        }
        else
        {
            break;
        }
    }
    sum1=l;
    l=1;
    reverse(a.begin(),a.end());
    for(int i=1;i<n;++i)
    {
        v=a[i];
        if(u==v)
        {
            ++l;
        }
        else
        {
            break;
        }
    }
    sum2=l;
    if(a[n-1]!=a[0])
    {
        sum2=0;
    }
    reverse(a.begin(),a.end());
    if((sum1+sum2)>=(n-k))
    {
        cout<<"tokitsukaze";
        return 0;
    }
    u=((a[0]+1)%2);
    for(int i=1;i<n;++i)
    {
        v=a[i];
        if(u==v)
        {
            ++l;
        }
        else
        {
            break;
        }
    }
    sum1=l;
    l=1;
    reverse(a.begin(),a.end());
    for(int i=1;i<n;++i)
    {
        v=a[i];
        if(u==v)
        {
            ++l;
        }
        else
        {
            break;
        }
    }
    sum2=l;
    reverse(a.begin(),a.end());
    sum1=0;
    if(a[n-1]==a[0])
    {
        sum2=0;
    }
    if((sum1+sum2)>=(n-k))
    {
        cout<<"tokitsukaze";
        return 0;
    }
    if((sum1+sum2)==(2*n))
    {
        if(k==n)
        {
            cout<<"tokitsukaze";
            return 0;
        }
        else
        {
            cout<<"quailty";
            return 0;
        }
    }
    int zmin=100000000;
    int zmax=(-1);
    for(int i=0;i<n;++i)
    {
        if(a[i]==0)
        {
            zmin=min(zmin,i);
            zmax=max(zmax,i);
        }
    }
    if((zmax-zmin)>=(k+1))
    {
        cout<<"once again";
        return 0;
    }
    int onemin=100000000;
    int onemax=(-1);
    for(int i=0;i<n;++i)
    {
        if(a[i]==1)
        {
            onemin=min(onemin,i);
            onemax=max(onemax,i);
        }
    }
    if((onemax-onemin)>=(k+1))
    {
        cout<<"once again";
        return 0;
    }
    if(k==n)
    {
        cout<<"once again";
        return 0;
    }
    if(a[0]==1)
    {
        if(zmin>=onemax)
        {
            cout<<"once again";
            return 0;
        }
        else
        {
            cout<<"quailty";
            return 0;
        }
    }
    if(a[0]==0)
    {
        if(onemin>=zmax)
        {
            cout<<"once again";
            return 0;
        }
        else
        {
            cout<<"quailty";
            return 0;
        }
    }
    return 0;
}