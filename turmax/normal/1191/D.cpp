#include <bits/stdc++.h>

using namespace std;
#define int long long
int sum(vector <int> a)
{
    int s=0;
    for(int i=0;i<a.size();++i)
    {
        s+=a[i];
    }
    return s;
}
bool check(map <int,int> b,vector <int> a)
{
    for(int i=0;i<a.size();++i)
    {
        if(b[a[i]]>=2)
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a[i]=k;
    }
    map <int,int> b;
    for(int i=0;i<n;++i)
    {
        if(b.count(a[i])==1)
        {
            b[a[i]]++;
        }
        else
        {
            b[a[i]]=1;
        }
    }
    bool f=true;
    for(int i=0;i<n;++i)
    {
        if(b[a[i]]>=2)
        {
        f=false;
        b[a[i]]--;
        if(a[i]==0)
        {
            cout<<"cslnb";
            return 0;
        }
        if(b.count(a[i]-1)==1)
        {
            b[a[i]-1]++;
        }
        else
        {
            b[a[i]-1]=1;
        }
        if(check(b,a)==false)
        {
            cout<<"cslnb";
            return 0;
        }
        break;
        }
    }
    if((sum(a)-(n*(n-1))/2)%2!=0)
    {
        cout<<"sjfnb";
        return 0;
    }
    else
    {
        cout<<"cslnb";
        return 0;
    }
    return 0;
}