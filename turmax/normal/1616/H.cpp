#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=3e5+5;
int po2[maxn];
int slv2(vector <int> a,vector <int> b,int x,int bt);
int slv1(vector <int> a,int x,int bt)
{
    if(a.empty()) return 0;
    if(bt==(-1))
    {
        if(x==0) return (po2[a.size()]-1)%p;
        else return 0;
    }
    int n=a.size();
    vector <int> a0,a1;
    for(int i=0;i<n;++i)
    {
        if(a[i] & (1<<bt)) a1.push_back(a[i]);
        else a0.push_back(a[i]);
    }
    if(x<(1<<bt))
    {
        return (slv1(a0,x,bt-1)+slv1(a1,x,bt-1))%p;
    }
    else
    {
        return (slv2(a0,a1,x-(1<<bt),bt-1)+po2[a0.size()]+po2[a1.size()]-2)%p;
    }
}
int slv2(vector <int> a,vector <int> b,int x,int bt)
{
    if(a.empty() || b.empty()) return 0;
    if(bt==(-1))
    {
        if(x==0) return ((po2[a.size()]-1)*(po2[b.size()]-1))%p;
        else return 0;
    }
    int n=a.size();
    vector <int> a0,a1;
    for(int i=0;i<n;++i)
    {
        if(a[i] & (1<<bt)) a1.push_back(a[i]);
        else a0.push_back(a[i]);
    }
    int m=b.size();
    vector <int> b0,b1;
    for(int i=0;i<m;++i)
    {
        if(b[i] & (1<<bt)) b1.push_back(b[i]);
        else b0.push_back(b[i]);
    }
    if(x<(1<<bt))
    {
        return (slv2(a0,b0,x,bt-1)+slv2(a1,b1,x,bt-1))%p;
    }
    else
    {
        int o1=slv2(a0,b1,x-(1<<bt),bt-1);int o2=slv2(a1,b0,x-(1<<bt),bt-1);o1%=p;o2%=p;
        //cout<<o1<<" o1 "<<o2<<" o2 "<<a0.size()<<" a0 "<<a1.size()<<" a1 "<<b0.size()<<" b0 "<<b1.size()<<" b1 "<<endl;
        int ans=(o1*((po2[b0.size()]+po2[a1.size()]-1)%p)+o2*((po2[b1.size()]+po2[a0.size()]-1)%p)+o1*o2+(po2[a0.size()]-1)*(po2[b0.size()]-1)+(po2[a1.size()]-1)*(po2[b1.size()]-1))%p;
        //cout<<ans<<" ans "<<endl;
        return ans;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    po2[0]=1;
    for(int i=1;i<maxn;++i) po2[i]=(po2[i-1]*2)%p;
    int n,x;
    cin>>n>>x;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=slv1(a,x,30);
    cout<<(ans%p+p)%p;
    return 0;
}