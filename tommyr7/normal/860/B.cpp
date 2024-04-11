#include <bits/stdc++.h>
#define Maxn 70007
#define p1 998244353
#define p2 100000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
string s[Maxn];
pair<int,int> ans;
map<pair<int,int>,int> mp;
map<pair<int,int>,bool> vis;
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		s[i].clear();
		char ch;
		for (int j=1;j<=9;j++)
		{
			ch=getchar();
			s[i]+=ch;
		}
		if (i<n) ch=getchar();
	}
	mp.clear();
	for (int i=1;i<=n;i++)
	{
		int len=s[i].length();
		vis.clear();
		for (int lx=0;lx<len;lx++)
		{
			int now1=0,now2=0;
			for (int rx=lx;rx<len;rx++)
			{
				now1=(27LL*now1%p1+s[i][rx])%p1;
				now2=(27LL*now2%p2+s[i][rx])%p2;
				if (!vis[make_pair(now1,now2)]) 
				{
					++mp[make_pair(now1,now2)];
					vis[make_pair(now1,now2)]=true;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		int t=15;
		ans=make_pair(0,0);
		int len=s[i].length();
		int now1=0,now2=0;
		for (int lx=0;lx<len;lx++)
		{
			int now1=0,now2=0;
			for (int rx=lx;rx<len;rx++)
			{
				now1=(27LL*now1%p1+s[i][rx])%p1;
				now2=(27LL*now2%p2+s[i][rx])%p2;
				if (mp[make_pair(now1,now2)]==1&&rx-lx+1<t)
				{
					t=rx-lx+1;
					ans=make_pair(lx,rx);
				}
			}
		}
		for (int j=ans.first;j<=ans.second;j++)
			printf("%c",s[i][j]);
		printf("\n");
	}
	return 0;
}