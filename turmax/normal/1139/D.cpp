#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
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
    int ans=0;
    int sum=0;
    for(int i=2;i<=n;++i)
    {
        vector <int> v=rasl(i);
        sort(v.begin(),v.end());
        int sz=v.size();
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.size()==sz)
        {
            int u=(n/i)*inv(n);
            u%=p;
            int r=inv(1-u)-1;
            r%=p;
            if(sz%2==1)
            {
               ans-=r;
            }
            else
            {
                ans+=r;
            }
            ans%=p;
        }
    }
    cout<<((-ans+1)%p+p)%p;
    return 0;
}