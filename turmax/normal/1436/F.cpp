#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=1e5+5;
int cnt[maxn];
int po(int a,int b)
{
    if(b<0)
    {
        return po(a,p-1+b);
    }
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
    for(int i=0;i<n;++i)
    {
        int pos,x;
        cin>>pos>>x;
        cnt[pos]=x;
    }
    int ans=0;
    for(int i=1;i<maxn;++i)
    {
        int ans1=0;
        vector <int> v=rasl(i);
        int sz=v.size();
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.size()!=sz) continue;
        int o=1;
        for(int i=0;i<v.size();++i) o*=(-1);
        int c=0;
        int c1=0;
        int s=0;
        int s2=0;
        int sum1=0;
        for(int j=i;j<maxn;j+=i)
        {
            c+=cnt[j];
            c1+=cnt[j];
            sum1+=cnt[j];
            c1%=(p-1);
            s+=(cnt[j]*j);
            s2+=((cnt[j]*j)%p)*j;
            s%=p;
            s2%=p;
            c%=p;
        }
        if(sum1==0) continue;
        if(sum1==1) continue;
        ans1+=((o*s2*po(2,c1-2))%p)*(c-1);
        ans1+=o*((s*s-s2)%p)*(((c-2)*po(2,c1-3)+po(2,c1-2))%p);
        ans1%=p;
        ans+=ans1;
        ans%=p;
    }
    ans%=p;ans+=p;ans%=p;
    cout<<ans;
    return 0;
}