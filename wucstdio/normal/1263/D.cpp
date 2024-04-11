#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,pa[500005],last[26];
char s[105];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int m=(int)strlen(s+1);
		for(int j=1;j<=m;j++)
		{
			if(last[s[j]-'a'])
			{
				int u=find(i);
				int v=find(last[s[j]-'a']);
				pa[u]=v;
			}
			last[s[j]-'a']=i;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	  if(find(i)==i)ans++;
	printf("%d\n",ans);
	return 0;
}