#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
int slv1(vector <int> a,vector <int> b)
{
    //cout<<a.size()<<' '<<b.size()<<endl;
    //cout<<" tgfrde "<<endl;
    //for(auto v:a) cout<<v<<' ';
    //cout<<endl;
    //for(auto v:b) cout<<v<<' ';
    //cout<<endl;
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    int summi=0;
    int sum=0;
    for(int i=0;i<a.size();++i)
    {
        int o=b.end()-upper_bound(b.begin(),b.end(),a[i]);
        summi+=(a[i]*o);
        sum+=(a[i]*b.size());
    }
    for(int i=0;i<b.size();++i)
    {
        int o=a.end()-lower_bound(a.begin(),a.end(),b[i]);
        summi+=(b[i]*o);
        sum+=(b[i]*a.size());
    }
    return (sum-summi);
}
int slv(int l,int r)
{
    //cout<<l<<" "<<r<<endl;
    vector <int> z;
    for(int i=l;i<r;++i)
    {
        if(s[i]=='0')
        {
            z.push_back(i);
        }
    }
    if(z.size()==0)
    {
        int u=(r-l);
        return (u*(u+1)*(u+2))/6;
    }
    if(z.size()==(r-l))
    {
        return 0;
    }
    int x=z[z.size()/2];
    if(x==l) ++x;
    int res=slv(l,x)+slv(x,r);
    vector <int> lef;
    vector <int> ri;
    int curr=0;
    int ans=0;
    for(int i=(x-1);i>=l;i--)
    {
        if(s[i]=='1')
        {
            ++curr;
            ans=max(ans,curr);
        }
        else
        {
            curr=0;
        }
        lef.push_back(ans);
    }
    curr=0;
    ans=0;
    for(int i=x;i<r;++i)
    {
        if(s[i]=='1')
        {
            ++curr;
            ans=max(ans,curr);
        }
        else
        {
            curr=0;
        }
        ri.push_back(ans);
    }
    res+=slv1(lef,ri);
    //cout<<l<<" "<<r<<" "<<res<<" res "<<endl;
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cin>>s;
    cout<<slv(0,n);
    return 0;
}