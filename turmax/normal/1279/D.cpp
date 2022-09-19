#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        return (a*po(a,b-1))%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    map <int,int> o;
    map <int,int> o1;
    vector <int> keys;
    int x;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        int k;
        cin>>k;
        sum+=k;
        for(int i=0;i<k;++i)
        {
            cin>>x;
            if(o.count(x)==0)
            {
                o[x]=inv(k);
                o1[x]=1;
                keys.push_back(x);
            }
            else
            {
                o[x]+=inv(k);
                o[x]%=p;
                o1[x]++;
            }
        }
    }
    sum%=p;
    int u=(n*n);
    u%=p;
    int r=0;
    int z;
    //cout<<u<<endl;
    for(int i=0;i<keys.size();++i)
    {
        z=o1[keys[i]];
        r+=(z*o[keys[i]]);
        r%=p;
    }
    cout<<(inv(u)*r)%p;
    return 0;
}