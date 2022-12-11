#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<int,int> mp;
int n,m;
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int pos=read(),val=read();
		mp[pos]=max(mp[pos],val);
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		int pos=read(),val=read();
		mp[pos]=max(mp[pos],val);
	}
	long long ans=0;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		ans+=(*it).second;
	printf("%lld\n",ans);
	return 0;
}