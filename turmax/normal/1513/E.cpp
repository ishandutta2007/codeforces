#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e5+5;
int fact[maxn];
int invf[maxn];
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
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    int ans=fact[n];
    ans*=invf[k];
    ans%=p;
    ans*=invf[n-k];
    ans%=p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        fact[i]=u;
        invf[i]=inv(fact[i]);
        u*=(i+1);
        u%=p;
    }
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;++i) {cin>>a[i];sum+=a[i];}
    if((sum%n)!=0)
    {
        cout<<0;
        return 0;
    }
    int c1=0,c2=0;
    vector <int> v1,v2;
    for(int i=0;i<n;++i)
    {
        if(a[i]>(sum/n)) {++c1;v1.push_back(a[i]);}
        else if(a[i]<(sum/n)) {++c2;v2.push_back(a[i]);}
    }
    map <int,int> o1;
    vector <int> keys1;
    for(auto h:v1)
    {
        if(o1.count(h)) o1[h]++;
        else {o1[h]=1;keys1.push_back(h);}
    }
    map <int,int> o2;
    vector <int> keys2;
    for(auto h:v2)
    {
        if(o2.count(h)) o2[h]++;
        else {o2[h]=1;keys2.push_back(h);}
    }
    int res1=1;
    for(auto l1:keys1) {res1*=invf[o1[l1]];res1%=p;}
    for(auto l2:keys2) {res1*=invf[o2[l2]];res1%=p;}
    int o=c(n,c1+c2);
    o*=fact[c1];
    o%=p;
    o*=fact[c2];
    o%=p;
    o*=res1;
    o%=p;
    int ans;
    if(c1>=2 && c2>=2)
    {
        ans=2;
    }
    else if(c1==0 && c2==0)
    {
        ans=1;
    }
    else
    {
        assert(c1!=0 && c2!=0);
        ans=(c1+c2);
    }
    cout<<(ans*o)%p;
    return 0;
}