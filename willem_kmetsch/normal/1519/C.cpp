#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}

int n,m,k;
int s[N],a[N];
vector<int> v[N];
set<int> S;
vector<int> del;
bool cmp(int x,int y){return x>y;}
void solve()
{
    rd(n);
    for (int i=1;i<=n;i++) v[i].clear();
    for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=n;i++) rd(s[i]),v[a[i]].push_back(s[i]);
    for (int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp);
    for (int i=1;i<=n;i++) for (int j=1;j<v[i].size();j++) v[i][j]+=v[i][j-1];
    S.clear();for (int i=1;i<=n;i++) S.insert(i);
    for (int k=1;k<=n;k++)
    {
        del.clear();
        int ans=0;
        for (int x:S) 
        {
            if (k>v[x].size()) {del.push_back(x);continue;}
            int sz=v[x].size();
            ans+=v[x][sz/k*k-1];
        }
        cout<<ans<<" ";
        for (int x:del) S.erase(x);
    }
    puts("");

}
signed main()
{
	int T;cin>>T;while (T--) solve();

}