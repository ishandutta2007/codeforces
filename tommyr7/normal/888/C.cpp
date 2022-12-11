#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n;
int f[Maxn][26];
bool vis[26];
char s[Maxn];
bool check(int len)
{
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++)
			f[i][j]=f[i-1][j];
		++f[i][s[i-1]-'a'];
	}
	memset(vis,true,sizeof(vis));
	for (int i=len;i<=n;i++)
		for (int j=0;j<26;j++)
			if (f[i][j]-f[i-len][j]==0) vis[j]=false;
	for (int i=0;i<26;i++)
		if (vis[i]) return true;
	return false;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	int lx=1,rx=n;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (check(mid)) rx=mid; else lx=mid;
	}
	if (check(lx)) printf("%d\n",lx); else printf("%d\n",rx);
	return 0;
}