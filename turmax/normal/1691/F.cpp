#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
const int maxn=2e5+5;
int fact[maxn];int invf[maxn];
int c(int n,int k)
{
    if(n<k || k<0 || n<0) return 0;
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;
}
vector <int> a[maxn];
bool used[maxn];
int sub[maxn];
int sumsq[maxn];
int corn[maxn];
vector<int> o;
int n,k;
void dfs(int x)
{
    used[x]=true;
    sub[x]=1;
    for(int v:a[x])
    {
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            dfs(v);
            o.push_back(sub[v]);
            sub[x]+=sub[v];
            sumsq[x]+=sub[v]*sub[v];
        }
    }
    sumsq[x]+=(n-sub[x])*(n-sub[x]);
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;invf[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
    vector<pair<int,int> > b;
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);b.push_back({x,y});
    }
    dfs(0);
    int ans=c(n,k)*((n*n)%p);ans%=p;
    for(auto [x,y]:b)
    {
        if(corn[x]>corn[y]) swap(x,y);
        {
        int o=sub[y];int ans1=c(o,k);ans-=(ans1*(n-o+n-o-1));ans%=p;
        int sumsq1=(sumsq[x]-o*o);int sum1=n-1-o;
        ans-=((sum1*sum1-sumsq1)%p)*ans1;ans%=p;
        }
        {
        swap(x,y);
        int o=n-sub[x];int ans1=c(o,k);ans-=(ans1*(n-o+n-o-1));ans%=p;
        int sumsq1=(sumsq[x]-o*o);int sum1=n-1-o;
        ans-=((sum1*sum1-sumsq1)%p)*ans1;ans%=p;
        }
    }
    cout<<(ans%p+p)%p;
    return 0;
}