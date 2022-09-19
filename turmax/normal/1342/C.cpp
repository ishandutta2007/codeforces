#include <bits/stdc++.h>

using namespace std;
#define int long long
int sum(vector <bool> v)
{
    int ans=0;
    for(int i=0;i<v.size();++i)
    {
        if(v[i])
        {
            ++ans;
        }
    }
    return ans;
}
int go(int x,int s,int n,vector <int> &pr)
{
    int u=(x%n);
    int ans=(x/n)*s;
    return pr[u]+ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int a,b,q;
    cin>>a>>b>>q;
    vector <bool> v(a*b);
    for(int i=0;i<(a*b);++i)
    {
        v[i]=(((i%a)%b)!=((i%b)%a));
    }
    int s=sum(v);
    vector <int> pr(a*b+1);
    pr[0]=0;
    for(int i=1;i<=a*b;++i)
    {
        pr[i]=pr[i-1]+((int) v[i]);
    }
    while(q--)
    {
    int l,r;
    cin>>l>>r;
    cout<<-go(l-1,s,a*b,pr)+go(r,s,a*b,pr)<<" ";
    }
    cout<<endl;
    }
    return 0;
}