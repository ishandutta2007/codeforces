#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
typedef long long ll;
int Q,op;
char s[maxn];
vector<int> v;
bool has[maxn];
map<ll,int> g[maxn];
const ll bas1=31,bas2=37;
const ll mod1=998244353,mod2=1000000007;
const ll B=1000000009;
ll xp1[maxn],xp2[maxn];
ll hs1[maxn],hs2[maxn];
ll Lcnt[maxn],Rcnt[maxn];
ll query1(int l,int r)
{
    ll x=hs1[r]-hs1[l-1]*xp1[r-l+1]%mod1;
    x=(x%mod1+mod1)%mod1;
    return x;
}
ll query2(int l,int r)
{
    ll x=hs2[r]-hs2[l-1]*xp2[r-l+1]%mod2;
    x=(x%mod2+mod2)%mod2;
    return x;
}
int main()
{
	xp1[0]=xp2[0]=1;
	for(int i=1;i<=300000;++i)
	{
		xp1[i]=xp1[i-1]*bas1%mod1;
		xp2[i]=xp2[i-1]*bas2%mod2;
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&op);
		scanf("%s",s+1);
		if(op==1)
		{
			int n=strlen(s+1);
			ll h1=0,h2=0;
			for(int i=1;i<=n;++i)
			{
				h1=(h1*bas1+s[i]-'a'+1)%mod1;
				h2=(h2*bas2+s[i]-'a'+1)%mod2; 
			}
			ll hval=h1*B+h2;
			if(!has[n])v.push_back(n),has[n]=1;
			g[n][hval]++;
		}
		else if(op==2)
		{
			int n=strlen(s+1);
			ll h1=0,h2=0;
			for(int i=1;i<=n;++i)
			{
				h1=(h1*bas1+s[i]-'a'+1)%mod1;
				h2=(h2*bas2+s[i]-'a'+1)%mod2; 
			}
			ll hval=h1*B+h2;
			g[n][hval]--;
		}
		else if(op==3)
		{
			int n=strlen(s+1);
			for(int i=1;i<=n;++i)
			{
				hs1[i]=(hs1[i-1]*bas1+s[i]-'a'+1)%mod1;
				hs2[i]=(hs2[i-1]*bas2+s[i]-'a'+1)%mod2;
			}
			ll ans=0;
			for(int i=1;i<=n;++i)
			{
				for(int len:v)if(i>=len)
				{
					int l=i-len+1,r=i;
					ll hval=query1(l,r)*B+query2(l,r);
					if(!g[len].count(hval))continue;
					ans+=g[len][hval];
				}
			}
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
}