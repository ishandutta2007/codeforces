#include <bits/stdc++.h>
using namespace std;
int n;
map<int,bool> mp[107];
int ans[107];
int main()
{
	scanf("%d",&n);
	mp[0][0]=true;
	ans[0]=1;
	for (int i=1;i<=20;i++)
	{
		for (map<int,bool>::iterator it=mp[i-1].begin();it!=mp[i-1].end();it++)
		{
			int p=(*it).first;
			if (!mp[i][p+1])
			{
				mp[i][p+1]=true;
				++ans[i];
			}
			if (!mp[i][p+5])
			{
				mp[i][p+5]=true;
				++ans[i];
			}
			if (!mp[i][p+10])
			{
				mp[i][p+10]=true;
				++ans[i];
			}
			if (!mp[i][p+50])
			{
				mp[i][p+50]=true;
				++ans[i];
			}
		}
	}
	if (n<=20) printf("%d\n",ans[n]); else printf("%lld\n",49LL*(n-20)+733);
	return 0;
}