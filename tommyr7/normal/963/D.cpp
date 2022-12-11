#include <bits/stdc++.h>
#define Maxn 200007
#define blocks 40
#define ull unsigned long long
#define modp 5000007
using namespace std;
char s[Maxn],g[Maxn];
int n,q,k;
ull h[Maxn],bin[Maxn];
int pos[Maxn],cnt;
int tot=0,x;
vector<vector<int> >t;
vector<int> tt;
ull get_hash(int lx,int rx)
{
	return (h[rx]-((ull)h[lx-1]*bin[rx-lx+1]));
}
int l[modp+1];
vector<ull> pre,other,mp;
int cntt=0;
inline void insert(int u,ull v)
{
    ++cntt;
	other.push_back(v);
	pre.push_back(l[u]);
	l[u]=cntt;
	mp.push_back(++tot);
}
inline int get(ull h)
{
	x=(int)h%modp;
	if (x<0) x+=modp;
	for (int q=l[x];q>-1;q=pre[q])
		if (other[q]==h) return mp[q];
	return 0;
}
inline void deal(ull h)
{
	x=(int)h%modp;
	if (x<0) x+=modp;
	insert(x,h);
}
int main()
{
    other.push_back(0);
    pre.push_back(0);
    mp.push_back(0);
	memset(l,-1,sizeof(l));
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		h[i]=((ull)29*h[i-1]+s[i]-'a'+1);
	bin[0]=1;
	for (int i=1;i<=n;i++)
		bin[i]=((ull)29*bin[i-1]);
	t.push_back(tt);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n&&j<i+blocks;j++)
		{
			ull now=get_hash(i,j);
			if (!get(now)) 
			{
				deal(now);
				t.push_back(tt);
			}
			int y=get(now);
			t[y].push_back(i);
		}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%s",&k,g+1);
		int len=strlen(g+1);
		if (len<=blocks)
		{
			ull now=0;
			for (int i=1;i<=len;i++)
				now=(29*now+g[i]-'a'+1);
			int y=get(now);
			if (y==0||t[y].size()<k) printf("%d\n",-1); else
			{
				cnt=(int)t[y].size();
				int ans=n;
				for (int i=0;i+k-1<cnt;i++)
					ans=min(ans,t[y][i+k-1]-t[y][i]+len);
				printf("%d\n",ans);
			}
		} else
		{
			cnt=0;
			ull now=0;
			for (int i=1;i<=len;i++)
				now=(29*now+g[i]-'a'+1);
			for (int i=1;i+len-1<=n;i++)
				if (get_hash(i,i+len-1)==now) pos[++cnt]=i;
			if (cnt<k) printf("%d\n",-1); else
			{
				int ans=n;
				for (int i=1;i+k-1<=cnt;i++)
					ans=min(ans,pos[i+k-1]-pos[i]+len);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}