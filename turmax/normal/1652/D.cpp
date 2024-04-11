#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod=998244353;
const int maxn=2e5+5;
vector<vector<int> > a[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) {int u=po(a,b/2);return (u*u)%mod;}
    else {int u=po(a,b-1);return (a*u)%mod;}
}
int inv(int x)
{
    return po(x,mod-2);
}
vector<int> rasl(int x)
{
	vector<int> ans;
	if(x==1) return ans;
	for(int i=2;i*i<=x;++i)
	{if(x%i==0) {ans=rasl(x/i);ans.push_back(i);return ans;}}
	ans.push_back(x);return ans;
}
vector <int> ras[maxn];
bool used[maxn];
int cnt[maxn];
int mi[maxn];
int val=1;
int vals[maxn];
vector<int> z;
void dfs(int x)
{
    used[x]=true;
for(auto h:a[x])
{
	if(!used[h[0]])
	{
	    val=vals[x];
	    for(int p:ras[h[2]]) {val*=p;val%=mod;cnt[p]++;z.push_back(p);}
		for(int p:ras[h[1]]) {val*=inv(p);val%=mod;z.push_back(p);cnt[p]--;mi[p]=min(mi[p],cnt[p]);}
		vals[h[0]]=val;
		dfs(h[0]);
		for(int p:ras[h[2]]) {cnt[p]--;}
		for(int p:ras[h[1]]) {cnt[p]++;}
	}
}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i) ras[i]=rasl(i);
    int t;
    cin>>t;
    while(t--)
    {
        z.clear();
        vals[0]=1;
        int n;cin>>n;
        for(int i=0;i<n;++i) {used[i]=false;a[i].clear();}
        for(int i=0;i<n-1;++i) {int x,y,z,t;cin>>x>>y>>z>>t;--x;--y;a[x].push_back({y,z,t});a[y].push_back({x,t,z});}
        dfs(0);
        int ans=0;for(int i=0;i<n;++i) {ans+=vals[i];ans%=mod;}
        sort(z.begin(),z.end());z.erase(unique(z.begin(),z.end()),z.end());
        for(int p:z)
        {
            if(ras[p].size()==1)
            {
                ans*=po(p,-mi[p]);
                ans%=mod;
            }
        }
        for(int p:z) {mi[p]=0;cnt[p]=0;}
        z.clear();
        cout<<ans<<'\n';
    }
    return 0;
}