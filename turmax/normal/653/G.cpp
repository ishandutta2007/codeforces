#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=3e5+5;
bool used[maxn];int cnt[maxn];int fact[maxn];int invf[maxn];int c1[maxn];int pr[maxn];
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
int c(int n,int k) {int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;}
vector <int> v[maxn];
int n;
int f(vector <int> v)
{
    sort(v.begin(),v.end());reverse(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<v.size();++i)
    {
        ans-=pr[i]*v[i];ans%=p;ans+=pr[n-i-1]*v[i];ans%=p;
    }
    return (ans%p+p)%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;invf[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
    cin>>n;
    for(int i=0;i<=n-1;++i) c1[i]=c(n-1,i);
    for(int i=0;i<=n-1;++i) pr[i+1]=(pr[i]+c1[i])%p;
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];cnt[a[i]]++;}
    used[0]=true;used[1]=true;
    int ans=0;
    for(int i=2;i<maxn;++i)
    {
        if(used[i]) continue;
        for(int j=i;j<maxn;j+=i)
        {
            int o=0;int u=j;while(u%i==0) {++o;u/=i;}
            used[j]=true;
            for(int k=0;k<cnt[j];++k) {v[i].push_back(o);}
        }
    }
    for(int i=2;i<maxn;++i)
    {
        if(!v[i].empty())
        {
            ans+=f(v[i]);
            ans%=p;
        }
    }
    cout<<(ans%p+p)%p;
    return 0;
}