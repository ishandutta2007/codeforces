#include<bits/stdc++.h>
#define maxn 255
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int n,m;
char a[maxn][maxn];
const ull bas = 37;
const ull inf = (ull)1e18;
ull xp[26];
ull hs[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
ull s[maxn];
int c[26];
struct Manacher
{
	ull s[maxn*2];
	int p[maxn*2],n;
	void init(ull *str,int len)
	{
		for(int i=0;i<=n;++i)s[i]=0;
		n=0;
		s[0]=inf;
		s[++n]=inf*2;
		for(int i=1;i<=len;++i)
		{
			s[++n]=str[i];
			s[++n]=inf*2;
		}
		s[++n]=inf*3;
	}
	vector<int> solve()
	{
		vector<int> Ans;
		Ans.resize(n+1);
		int j=1,mx=1;
	    for(int i=1;i<=n;++i)
	    {
	        if(i<mx)p[i]=min(mx-i,p[j*2-i]);
	        else p[i]=1;
	        while(s[i-p[i]]==s[i+p[i]])p[i]++;
	        if(mx<i+p[i])j=i,mx=i+p[i];
	        Ans[i]=p[i]-1;
	    }
	    return Ans;
	}
}manacher;
int main()
{
	xp[0]=1;
	for(int i=1;i<=250;++i)xp[i]=xp[i-1]*bas;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i)
	{
		for(int L=1;L<=m;++L)
		{
			ull h=0;
			memset(c,0,sizeof(c));
			for(int R=L;R<=m;++R)
			{
				h=h+xp[a[i][R]-'a'];
				hs[L][R][i]=h;
				c[a[i][R]-'a']++;
				int tot=0;
				for(int j=0;j<26;++j)if(c[j]&1)++tot;
				if(tot<=1)vis[L][R][i]=1;
			}
		}
	}
	ll ans=0;
	for(int L=1;L<=m;++L)
	{
		for(int R=L;R<=m;++R)
		{
			int len=0;
			for(int i=1;i<=n+1;++i)
			{
				if(vis[L][R][i])s[++len]=hs[L][R][i];
				else
				{
					manacher.init(s,len);
					vector<int> Ans=manacher.solve();
					for(int i=1;i<Ans.size();++i)ans+=(Ans[i]+1)/2;
					len=0;
				}
			}
		}
	}
	printf("%lld\n",ans);
}