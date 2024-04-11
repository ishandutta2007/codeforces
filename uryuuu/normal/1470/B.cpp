#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ch(a) (int(a-'a')+1)
#define chh(a) (int(a-'A')+1)
#define mm(a) memset(a,0,sizeof(a))
#define Erica_1031 Errrica'u'
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define inf  0x7FFFFFFF
#define Inf  0x3F3F3F3F
#define odd(n) (n&1)
#define even(n) (!(n&1))
#define lb(x) (x&(-x))
#define endl '\n'
#define sset set<int>::iterator it=s.begin();it!=s.end();++it
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int Maxx=3*1e6+66;
long long mod=998244353;
int t,n,q,ans0,ans1;
ll w;
int sq[1111];
int vis[1000009];
int vvs[1000009];
unordered_map<int,int>mp;
int a[Maxx];
void solve()
{
    mp.clear();scanf("%d",&n);rep(i,1,n) scanf("%d",&a[i]),++mp[vis[a[i]]];ans0=0,ans1=0;
    for(auto p:mp)
    {
        ans0=max(ans0,p.second);
        if(even(p.second))  ans1+=p.second;
    }
    if(mp[1]&1) ans1+=mp[1];
    ans1=max(ans1,ans0);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld",&w);
        if(w==0ll) {printf("%d\n",ans0);continue;}
        else printf("%d\n",ans1);
    }
}
int main()
{
    for(int i=1;i<=1000;++i) sq[i]=i*i;
    for(int i=1;i<=1000000;++i)
    {
        if(vvs[i]) continue;
        vvs[i]=1;
        for(int j=1;j<=1000;++j)
        {
            if(i*sq[j]>1000000) break;
            vis[i*sq[j]]=i;
            vvs[i*sq[j]]=1;
        }
    }
    scanf("%d",&t);
    // IOS;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}