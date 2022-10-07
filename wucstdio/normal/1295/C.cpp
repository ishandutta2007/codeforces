#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,m,nxt[26][100005],last[26];
char s[100005],t[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<26;i++)last[i]=n+1;
		for(int i=n;i>=0;i--)
		{
			for(int j=0;j<26;j++)nxt[j][i]=last[j];
			last[s[i]-'a']=i;
		}
		int ans=0;
		int now=1;
		while(now<=m)
		{
			if(last[t[now]-'a']==n+1)
			{
				ans=-1;
				break;
			}
			int p=0;
			while(now<=m&&nxt[t[now]-'a'][p]<=n)
			{
				p=nxt[t[now]-'a'][p];
				now++;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}