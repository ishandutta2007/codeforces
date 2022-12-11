#include <bits/stdc++.h>
using namespace std;
bool vis[30],viss[30];
int n,ans=0;
char s1[10],s2[100007];
int main()
{
	scanf("%d",&n);
	memset(vis,true,sizeof(vis));
	bool check=false;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%s%s",s1,s2);
		if (s1[0]=='!')
		{
			memset(viss,false,sizeof(viss));
			int len=strlen(s2);
			for (int j=0;j<len;j++)
				viss[s2[j]-'a'+1]=true;
			for (int i=1;i<=26;i++)
				if (!viss[i]) vis[i]=false;
			if (check) ++ans;
		} else if (s1[0]=='.')
		{
			int len=strlen(s2);
			for (int j=0;j<len;j++)
				vis[s2[j]-'a'+1]=false;
		} else
		{
			int len=strlen(s2);
			for (int j=0;j<len;j++)
				vis[s2[j]-'a'+1]=false;
			if (check&&i!=n) ++ans;
		}
		cnt=0;
		for (int i=1;i<=26;i++)
			if (vis[i]) ++cnt;
		if (cnt<=1) check=true;
	}
	printf("%d\n",ans);
	return 0;
}