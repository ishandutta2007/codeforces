#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005];
int n,f[200005],g[26],res,now[35];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i]-'a'+1;j<26;j++)
		  f[i]=max(f[i],g[j]);
		f[i]++;
		g[s[i]-'a']=max(g[s[i]-'a'],f[i]);
		res=max(res,f[i]);
	}
	printf("%d\n",res);
	for(int i=1;i<=n;i++)
	{
		int j=res;
		while(now[j]>s[i]-'a')j--;
		printf("%d ",j);
		now[j]=s[i]-'a';
	}
	printf("\n");
	return 0;
}