#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(9)<<"";
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> next(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        next[i]=(i+1);
    }
    vector <double> b(n);
    int curr;
    for(int i=0;i<n;++i)
    {
        b[i]=a[i];
    }
    for(int i=(n-2);i>=0;--i)
    {
        while(next[i]<n && b[next[i]]<b[i])
        {
            //cout<<i<<endl;
            //cout<<next[i]<<endl;
            b[i]=(b[i]*(next[i]-i)+b[next[i]]*(next[next[i]]-next[i]))/(next[next[i]]-i);
            next[i]=next[next[i]];
        }
    }
    curr=0;
    for(int i=0;i<n;++i)
    {
        //cout<<curr<<endl;
        if(i>=next[curr])
        {
        curr=i;
        }
        else
        {
        b[i]=b[curr];
        }
    }
    curr=0;
    for(int i=0;i<n;++i)
    {
        //cout<<curr<<endl;
        if(i>=next[curr])
        {
        cout<<b[i]<<'\n';
        curr=i;
        }
        else
        {
        cout<<b[curr]<<'\n';
        }
    }
    return 0;
}